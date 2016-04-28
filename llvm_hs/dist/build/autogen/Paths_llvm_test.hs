module Paths_llvm_test (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch

version :: Version
version = Version [0] []
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/Users/MB/.cabal/bin"
libdir     = "/Users/MB/.cabal/lib/x86_64-osx-ghc-7.10.2/llvm-test-0-APQrLim0uZP4qyxshf0LLI"
datadir    = "/Users/MB/.cabal/share/x86_64-osx-ghc-7.10.2/llvm-test-0"
libexecdir = "/Users/MB/.cabal/libexec"
sysconfdir = "/Users/MB/.cabal/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "llvm_test_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "llvm_test_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "llvm_test_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "llvm_test_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "llvm_test_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
