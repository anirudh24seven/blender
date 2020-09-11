#pragma once

/** \file
 * \ingroup bli
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Compute MD5 message digest for LEN bytes beginning at BUFFER.  The
 * result is always in little endian byte order, so that a byte-wise
 * output yields to the wanted ASCII representation of the message
 * digest.  */

void *BLI_hash_md5_buffer(const char *buffer, size_t len, void *resblock);

/* Compute MD5 message digest for bytes read from STREAM.  The
 * resulting message digest number will be written into the 16 bytes
 * beginning at RESBLOCK.  */

int BLI_hash_md5_stream(FILE *stream, void *resblock);

char *BLI_hash_md5_to_hexdigest(void *resblock, char r_hex_digest[33]);

#ifdef __cplusplus
}
#endif
