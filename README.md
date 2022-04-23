[![Documentation Status](https://readthedocs.org/projects/tosee/badge/?version=latest)](https://readthedocs.org/projects/tosee/builds/)

# Tosee-Docs

Tosee documents: https://tosee.readthedocs.io/

## Usage

### Ubuntu

1. Install environment

    - Python==3.7

    ```shell
    cd ${tosee_doc_root}/
    pip install -r docs/requirements.txt
    ```

2. Build

    ```shell
    cd ${tosee_doc_root}/
    make html
    ```

3. See result

    ```shell
    cd ${tosee_doc_root}/
    google-chrome _build/html/index.html
    ```

## Development documents

1. readthedoc: https://docs.readthedocs.io/en/latest/index.html
2. sphinx: https://www.sphinx-doc.org/en/master/index.html
3. sphinx-theme: https://sphinx-themes.org/
4. reStructuredText: https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html
