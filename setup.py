from setuptools import Extension, setup, find_packages
packages = find_packages()

extensions = {
    "pycee.selectionSort":["pycee/selectionSort.c"],
    "pycee.reverse":["pycee/rev.c"]
    }
ext_modules = [Extension(key, sources=sources) for key,sources in extensions.items()]

setup(name = "pycee",
      author = "Jay Rambhia",
      author_email = "jayrambhia777@gmail.com",
      version = "0.1",
      packages=packages,
      ext_modules=ext_modules)
