# Pybind11 Examples

[Pybind11 Docs](https://pybind11.readthedocs.io/en/latest/index.html)


## CMake Build and Test

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
export PYTHONPATH=./build:$PYTHONPATH # 导出路径
python ../test.py  # 运行测试程序
```

## Python Setuptools

```
pip install . # 安装
python test.py # 测试

# pip uninstall examples #卸载
```