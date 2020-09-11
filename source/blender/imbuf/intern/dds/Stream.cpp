/** \file
 * \ingroup imbdds
 */

#include <Stream.h>

#include <stdio.h>   // printf
#include <string.h>  // memcpy

static const char *msg_error_seek = "DDS: trying to seek beyond end of stream (corrupt file?)";
static const char *msg_error_read = "DDS: trying to read beyond end of stream (corrupt file?)";

unsigned int Stream::seek(unsigned int p)
{
  if (p > size) {
    set_failed(msg_error_seek);
  }
  else {
    pos = p;
  }

  return pos;
}

unsigned int mem_read(Stream &mem, unsigned long long &i)
{
  if (mem.pos + 8 > mem.size) {
    mem.set_failed(msg_error_seek);
    return 0;
  }
  memcpy(&i, mem.mem + mem.pos, 8);  // @@ todo: make sure little endian
  mem.pos += 8;
  return 8;
}

unsigned int mem_read(Stream &mem, unsigned int &i)
{
  if (mem.pos + 4 > mem.size) {
    mem.set_failed(msg_error_read);
    return 0;
  }
  memcpy(&i, mem.mem + mem.pos, 4);  // @@ todo: make sure little endian
  mem.pos += 4;
  return 4;
}

unsigned int mem_read(Stream &mem, unsigned short &i)
{
  if (mem.pos + 2 > mem.size) {
    mem.set_failed(msg_error_read);
    return 0;
  }
  memcpy(&i, mem.mem + mem.pos, 2);  // @@ todo: make sure little endian
  mem.pos += 2;
  return 2;
}

unsigned int mem_read(Stream &mem, unsigned char &i)
{
  if (mem.pos + 1 > mem.size) {
    mem.set_failed(msg_error_read);
    return 0;
  }
  i = (mem.mem + mem.pos)[0];
  mem.pos += 1;
  return 1;
}

unsigned int mem_read(Stream &mem, unsigned char *i, unsigned int cnt)
{
  if (mem.pos + cnt > mem.size) {
    mem.set_failed(msg_error_read);
    return 0;
  }
  memcpy(i, mem.mem + mem.pos, cnt);
  mem.pos += cnt;
  return cnt;
}

void Stream::set_failed(const char *msg)
{
  if (!failed) {
    puts(msg);
    failed = true;
  }
}
