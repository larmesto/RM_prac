from setuptools import find_packages
from setuptools import setup

setup(
    name='pure_pursuit_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('pure_pursuit_pkg', 'pure_pursuit_pkg.*')),
)
