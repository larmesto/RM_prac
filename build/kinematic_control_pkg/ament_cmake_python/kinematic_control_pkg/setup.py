from setuptools import find_packages
from setuptools import setup

setup(
    name='kinematic_control_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('kinematic_control_pkg', 'kinematic_control_pkg.*')),
)
