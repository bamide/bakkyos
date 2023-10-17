#include "main.h"

int custom_chdir(const char *path)
{
    if (path == NULL)
        return -1; /* Return an error code for an invalid path */

    /* Simulate changing the directory (provide your own implementation)
     * For simplicity, let's just print the desired path.
     */
    printf("Changing current working directory to: %s\n", path);
    return 0; /* Success */
}
