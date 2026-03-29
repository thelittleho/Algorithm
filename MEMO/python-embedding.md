# Python Embeding
## 1. 기본 단계 (Python/C API 사용)

파이썬 라이브러리(dll/so)를 C++ 코드에 연결하여 함수를 호출합니다.

1.  **헤더 포함:**  `<Python.h>`를 포함해야 합니다.
2.  **파이썬 인터프리터 초기화:**  `Py_Initialize()`  호출.
3.  **파이썬 모듈/함수 로드:**     `PyImport_ImportModule()`,  `PyObject_GetAttrString()`  등을 사용.   
4.  **인자 전달 및 함수 호출:**  `PyObject_CallObject()`를 사용하여 파이썬 객체를 호출.   
5.  **파이썬 종료:**  `Py_Finalize()`  호출.
 

## 2. 구체적인 예제 코드

Python 파일 (`script.py`)이 다음과 같을 때:

```python
# script.py
def add(a, b):
    return a + b

```

C++에서 호출하는 방법:
```cpp
#include <Python.h>
#include <iostream>

int main() {
    // 1. 파이썬 인터프리터 초기화
    Py_Initialize();

    // 2. 모듈(script.py) 가져오기
    PyObject* pName = PyUnicode_DecodeFSDefault("script");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // 3. 함수(add) 가져오기
        PyObject* pFunc = PyObject_GetAttrString(pModule, "add");

        if (pFunc && PyCallable_Check(pFunc)) {
            // 4. 인자 설정 및 호출
            PyObject* pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(10));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(20));

            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            // 5. 결과 값 가져오기
            if (pValue != NULL) {
                std::cout << "Result: " << PyLong_AsLong(pValue) << std::endl;
                Py_DECREF(pValue);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    // 6. 파이썬 종료
    Py_Finalize();
    return 0;
}

```

## 3. 컴파일 및 환경 설정 (Windows/Visual Studio)

-   **컴파일러 설정:**  x64로 설정해야 합니다.
-   **헤더/라이브러리 경로:**  Python 설치 경로의  `include`  및  `libs`  폴더를 프로젝트에 추가합니다.
-   **DLL 추가:**  `python3.dll`  및  `python3x.dll`이 프로젝트 실행 파일(.exe) 위치에 있어야 합니다.

## 4. 기타 연동 방법

-   **pybind11:**  C++11 이상에서 파이썬 연동을 쉽게 해주는 라이브러리입니다.
-   **System 명령:**  `system("python script.py")`와 같이 쉘 명령어를 사용할 수도 있지만, 복잡한 데이터 교환에는 부적합합니다.

**핵심 팁:**  
파이썬 C API 사용 시  `Py_DECREF`를 사용하여 참조 카운트(Reference Count)를 관리하지 않으면 메모리 누수가 발생할 수 있습니다.
