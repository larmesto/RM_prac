from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_laser_scan_matcher',
    version='0.0.0',
    packages=find_packages(
        include=('ros2_laser_scan_matcher', 'ros2_laser_scan_matcher.*')),
)
