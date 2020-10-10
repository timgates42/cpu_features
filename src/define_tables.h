#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2) [ENUM] = #NAME,
static const char* kFeatureNames[] = {
#include DEFINE_TABLE_DB_FILENAME
};
#undef FEATURE

#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2) [ENUM] = CPUINFO_FLAG,
static const char* kCpuInfoFlags[] = {
#include DEFINE_TABLE_DB_FILENAME
};
#undef FEATURE

#ifndef DEFINE_TABLE_DONT_GENERATE_HWCAPS
#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2) \
  [ENUM] = (HardwareCapabilities){HWCAP, HWCAP2},
static const HardwareCapabilities kHardwareCapabilities[] = {
#include DEFINE_TABLE_DB_FILENAME
};
#undef FEATURE
#endif  // DEFINE_TABLE_DONT_GENERATE_HWCAPS

#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2)     \
  static void set_##ENUM(const void* features, bool value) { \
    ((DEFINE_TABLE_FEATURE_TYPE*)features)->NAME = value;    \
  }                                                          \
  static int get_##ENUM(const void* features) {              \
    return ((DEFINE_TABLE_FEATURE_TYPE*)features)->NAME;     \
  }
#include DEFINE_TABLE_DB_FILENAME
#undef FEATURE

#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2) [ENUM] = set_##ENUM,
static void (*const kSetters[])(const void*, bool) = {
#include DEFINE_TABLE_DB_FILENAME
};
#undef FEATURE

#define FEATURE(ENUM, NAME, CPUINFO_FLAG, HWCAP, HWCAP2) [ENUM] = get_##ENUM,
static int (*const kGetters[])(const void*) = {
#include DEFINE_TABLE_DB_FILENAME
};
#undef FEATURE
