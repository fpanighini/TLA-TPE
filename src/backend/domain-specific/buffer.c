#include "buffer.h"
#include "../support/logger.h"

#include <stdlib.h>
#include <string.h>

Buffer * BufferInit(){
    Buffer * buf = malloc(sizeof(Buffer));
    if (buf == NULL) {
        return NULL;
    }
    buf->str = calloc(1, BUFFER_BLOCK);
    if (buf->str == NULL) {
        return NULL;
    }
    // (buf->str)[0] = '\0';
    buf->currentLen = 0;
    buf->maxLen = BUFFER_BLOCK;

    LogDebug("Buffer Created %s %d %d", buf->str, buf->currentLen, buf->maxLen);

    return buf;
}

void BufferFree(Buffer * buf) {
    if (buf != NULL){
        if (buf->str != NULL){
            free(buf->str);
        }
        free(buf);
    }
}

int ConcatString(Buffer * buf, char * string){
    return ConcatStringWithLength(buf, string, strlen(string));
}

int ConcatStringWithLength(Buffer * buf, char * string, int length){
    LogDebug("Drawing %s", string);
    LogDebug("Length: %d", buf->maxLen);
    if (!(buf->maxLen > buf->currentLen + length + 1)) {
        LogDebug("Attempting ConcatStringWithLength Malloc");
        int newLen = buf->maxLen + BUFFER_BLOCK;
        buf->str = realloc(buf->str, newLen);
        if (buf->str == NULL) {
            LogError("Buffer ConcatStringWithLength Realloc Failed");
            return 0;
        }
        buf->maxLen = newLen;
    }
    LogDebug("Strings: %s", "hola");
    LogDebug("Strings: %s", buf->str);
    strcpy(buf->str + buf->currentLen, string);
    buf->currentLen += length;
    return 0;
}


