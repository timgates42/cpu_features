#if defined(FEATURE)
// FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2)
// clang-format off
FEATURE(MIPS_MSA, msa, "msa", MIPS_HWCAP_MSA, 0)
FEATURE(MIPS_EVA, eva, "eva", 0, 0)
FEATURE(MIPS_R6, r6, "r6", MIPS_HWCAP_R6, 0)
// clang-format on
#else
#error "The FEATURE macro must be defined"
#endif  // FEATURE
