from distutils.core import setup, Extension

setup(name = "pyrev",
      author = "Jay Rambhia",
      author_email = "jayrambhia777@gmail.com",
      version = "0.1",
      ext_modules=[Extension("pyrev", ["pyrev/pyrev.c"])])
