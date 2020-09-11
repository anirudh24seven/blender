/** \file
 * \ingroup GHOST
 */

#pragma once

#include <exception>

class GHOST_XrException : public std::exception {
  friend class GHOST_XrContext;

 public:
  GHOST_XrException(const char *msg, int result = 0)
      : std::exception(), m_msg(msg), m_result(result)
  {
  }

  const char *what() const noexcept override
  {
    return m_msg;
  }

 private:
  const char *m_msg;
  int m_result;
};
