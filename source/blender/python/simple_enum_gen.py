# <pep8 compliant>

defs = """
    SPACE_EMPTY,
    SPACE_VIEW3D,
    SPACE_IPO,
    SPACE_OUTLINER,
    SPACE_BUTS,
    SPACE_FILE,
    SPACE_IMAGE,
    SPACE_INFO,
    SPACE_SEQ,
    SPACE_TEXT,
    SPACE_IMASEL, #Deprecated
    SPACE_SOUND, #Deprecated
    SPACE_ACTION,
    SPACE_NLA,
    SPACE_SCRIPT, #Deprecated
    SPACE_TIME, #Deprecated
    SPACE_NODE,
    SPACEICONMAX
"""

print('\tmod = PyModule_New("dummy");')
print('\tPyModule_AddObject(submodule, "key", mod);')

for d in defs.split('\n'):

    d = d.replace(',', ' ')
    w = d.split()

    if not w:
        continue

    try:
        w.remove("#define")
    except:
        pass

    # print w

    val = w[0]
    py_val = w[0]

    print('\tPyModule_AddObject(mod, "%s", PyLong_FromSize_t(%s));' % (val, py_val))
