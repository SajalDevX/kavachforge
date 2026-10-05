/* KavachForge regression test for KV-CLEANJ-001
 * CWE-125 - Out-of-bounds Read (heap) at cleanjson.c:27
 * Generated from proof-of-vulnerability sha256 24643574bbb6da66
 *
 * Drives the fuzz harness entry point with the exact input that crashed the
 * unpatched code. Under AddressSanitizer this test aborts if the fault is
 * reintroduced; it exits 0 when the fix holds. Build it with the same
 * sources + harness as the fuzzer, e.g.:
 *   cc -g -fsanitize=address -I<src> <sources> <harness> regress_kv_cleanj_001.c -o t && ./t
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size);

static const uint8_t kPoV_KV_CLEANJ_001[] = {
    0x43, 0x4a, 0x53, 0x4e, 0xff, 0xff, 0xff,
};

int main(void) {
    LLVMFuzzerTestOneInput(kPoV_KV_CLEANJ_001, sizeof(kPoV_KV_CLEANJ_001));
    printf("regression KV-CLEANJ-001: OK (no sanitizer fault on %zu-byte PoV)\n",
           sizeof(kPoV_KV_CLEANJ_001));
    return 0;
}
