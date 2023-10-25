from setuptools import Extension, setup

setup(
    name="happy",
    version="0.0.1",
    ext_modules=[
        Extension(
            name="happy",
            sources=["src/proxy.c"],
        ),
    ]
)
