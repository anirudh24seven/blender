/** \file
 * \ingroup collada
 */

#include "BLI_string.h"
#include <stddef.h>

#include "ExtraHandler.h"

ExtraHandler::ExtraHandler(DocumentImporter *dimp, AnimationImporter *aimp) : currentExtraTags(0)
{
  this->dimp = dimp;
  this->aimp = aimp;
}

ExtraHandler::~ExtraHandler()
{
}

bool ExtraHandler::elementBegin(const char *elementName, const char **attributes)
{
  /* \todo attribute handling for profile tags */
  currentElement = std::string(elementName);
  // addToSidTree(attributes[0], attributes[1]);
  return true;
}

bool ExtraHandler::elementEnd(const char *elementName)
{
  return true;
}

bool ExtraHandler::textData(const char *text, size_t textLength)
{
  char buf[1024];

  if (currentElement.length() == 0 || currentExtraTags == 0) {
    return false;
  }

  BLI_strncpy(buf, text, textLength + 1);
  currentExtraTags->addTag(currentElement, std::string(buf));
  return true;
}

bool ExtraHandler::parseElement(const char *profileName,
                                const unsigned long &elementHash,
                                const COLLADAFW::UniqueId &uniqueId)
{
  /* implement for backwards compatibility, new version added object parameter */
  return parseElement(profileName, elementHash, uniqueId, NULL);
}

bool ExtraHandler::parseElement(const char *profileName,
                                const unsigned long &elementHash,
                                const COLLADAFW::UniqueId &uniqueId,
                                COLLADAFW::Object *object)
{
  if (BLI_strcaseeq(profileName, "blender")) {
#if 0
    printf("In parseElement for supported profile %s for id %s\n",
           profileName,
           uniqueId.toAscii().c_str());
#endif
    currentUid = uniqueId;
    ExtraTags *et = dimp->getExtraTags(uniqueId);
    if (!et) {
      et = new ExtraTags(std::string(profileName));
      dimp->addExtraTags(uniqueId, et);
    }
    currentExtraTags = et;
    return true;
  }
  // printf("In parseElement for unsupported profile %s for id %s\n", profileName,
  // uniqueId.toAscii().c_str());
  return false;
}
