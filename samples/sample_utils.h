#ifndef NBP_SAMPLE_UTILS
#define NBP_SAMPLE_UTILS

#include <stdio.h>

static inline void write_message_to_file(const char *msg)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", msg);
        fclose(fp);  
    }
}

#endif // end if NBP_SAMPLE_UTILS
