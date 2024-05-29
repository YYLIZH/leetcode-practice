from setuptools import setup

setup(
    py_modules=["leetcode_practice"],
    entry_points={
        "console_scripts": ["create=leetcode_practice:main"],
    },
)
