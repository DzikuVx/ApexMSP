Import("env")
import os, shutil, glob

mingw_bin = os.path.join(
    os.path.expanduser("~"),
    ".platformio", "packages", "toolchain-gccmingw32", "bin"
)

# Make compiler available during the build.
env.PrependENVPath("PATH", mingw_bin)
os.environ["PATH"] = mingw_bin + os.pathsep + os.environ.get("PATH", "")

env.Replace(
    CC  = os.path.join(mingw_bin, "gcc.exe"),
    CXX = os.path.join(mingw_bin, "g++.exe"),
    AR  = os.path.join(mingw_bin, "ar.exe"),
    AS  = os.path.join(mingw_bin, "as.exe"),
)

# Copy MinGW runtime DLLs next to program.exe unconditionally, so they are
# present whenever PlatformIO runs the test binary.
build_dir = env.subst("$BUILD_DIR")
os.makedirs(build_dir, exist_ok=True)
for dll in glob.glob(os.path.join(mingw_bin, "lib*.dll")):
    shutil.copy(dll, os.path.join(build_dir, os.path.basename(dll)))
