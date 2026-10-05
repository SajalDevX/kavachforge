/* KavachForge regression test for KV-RECORD-001
 * CWE-787 - Out-of-bounds Write (heap) at recordcfg.c:54
 * Generated from proof-of-vulnerability sha256 30be9864d11d6fc7
 *
 * Drives the fuzz harness entry point with the exact input that crashed the
 * unpatched code. Under AddressSanitizer this test aborts if the fault is
 * reintroduced; it exits 0 when the fix holds. Build it with the same
 * sources + harness as the fuzzer, e.g.:
 *   cc -g -fsanitize=address -I<src> <sources> <harness> regress_kv_record_001.c -o t && ./t
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size);

static const uint8_t kPoV_KV_RECORD_001[] = {
    0x52, 0x43, 0x46, 0x31, 0x0c, 0x00, 0x23, 0x0a, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0xb5, 0xb5, 0xb5, 0xb5, 0xb5, 0x00, 0x00, 0x1a, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0xfe, 0x00, 0xfe, 0x00,
};

int main(void) {
    LLVMFuzzerTestOneInput(kPoV_KV_RECORD_001, sizeof(kPoV_KV_RECORD_001));
    printf("regression KV-RECORD-001: OK (no sanitizer fault on %zu-byte PoV)\n",
           sizeof(kPoV_KV_RECORD_001));
    return 0;
}
