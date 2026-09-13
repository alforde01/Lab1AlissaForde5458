#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void) {
    /*  dynamic library on macOS */
    void *handle = dlopen("./libcalc.dylib", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return 1;
    }

    dlerror(); 

    /* function pointers */
    double (*calc_add)(double, double) = (double (*)(double, double))dlsym(handle, "calc_add");
    double (*calc_sub)(double, double) = (double (*)(double, double))dlsym(handle, "calc_sub");
    double (*calc_mul)(double, double) = (double (*)(double, double))dlsym(handle, "calc_mul");
    double (*calc_div)(double, double) = (double (*)(double, double))dlsym(handle, "calc_div");

    char *error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "Error locating symbols: %s\n", error);
        dlclose(handle);
        return 1;
    }

    printf("2.0 + 2.0 = %.2f\n", calc_add(2.0, 2.0));
    printf("2.0 - 2.0 = %.2f\n", calc_sub(2.0, 2.0));
    printf("2.0 * 2.0 = %.2f\n", calc_mul(2.0, 2.0));
    printf("2.0 / 2.0 = %.2f\n", calc_div(2.0, 2.0));

    dlclose(handle);
    return 0;
}
