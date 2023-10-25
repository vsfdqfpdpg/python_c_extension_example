```bash
pip install check-wheel-contents wheel

python setup.py bdist_wheel

check-wheel-contents ./dist

pip install dist/happy-0.0.1-cp310-cp310-linux_x86_64.whl 
```

```
# PYTHON_INCLUDE_DIR
# PYTHON_LIBRARY
# python3 -c "import sysconfig; print(sysconfig.get_path('include'))"
# python3 -c "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))"
# cmake .. -DPYTHON_INCLUDE_DIR=$(python3 -c "from distutils.sysconfig import get_python_inc; print(get_python_inc())") -DPYTHON_LIBRARY=$(python3 -c "import distutils.sysconfig as sysconfig; print(sysconfig.get_config_var('LIBDIR'))")
```