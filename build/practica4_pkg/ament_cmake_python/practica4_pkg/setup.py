from setuptools import find_packages
from setuptools import setup

setup(
    name='practica4_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('practica4_pkg', 'practica4_pkg.*')),
)
