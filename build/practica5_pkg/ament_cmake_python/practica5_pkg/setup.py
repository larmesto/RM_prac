from setuptools import find_packages
from setuptools import setup

setup(
    name='practica5_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('practica5_pkg', 'practica5_pkg.*')),
)
