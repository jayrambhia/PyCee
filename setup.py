#from distutils.core import setup, Extension
from setuptools import Extension, setup, find_packages
packages = find_packages()

extensions = {
    "pycee.sort":["pycee/sort.c"],
    "pycee.selectionSort":["pycee/selectionSort.c"],
    "pycee.ccv":["pycee/ccv.c"]
    }
ext_modules = [Extension(key, sources=sources) for key,sources in extensions.items()]
print ext_modules
setup(name = "pycee",
      author = "Jay Rambhia",
      author_email = "jayrambhia777@gmail.com",
      version = "0.1",
      packages=packages,
      ext_modules=ext_modules)
