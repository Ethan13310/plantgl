"""
Provides QtNetwork classes and functions.
"""
import os
from openalea.plantgl.util.qt import QT_API, PYQT5_API, PYQT4_API, PYSIDE_API


if os.environ[QT_API] in PYQT5_API:
    from PyQt5.QtSvg import *
elif os.environ[QT_API] in PYQT4_API:
    from PyQt4.QtSvg import *
elif os.environ[QT_API] in PYSIDE_API:
    from PySide.QtSvg import *
