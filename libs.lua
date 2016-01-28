KORVPATH = path.getdirectory(_SCRIPT)
KORVLIB_INCLUDES = { KORVPATH .. "/src/" }
KORVLIB_LINKS = { }

function korv_use_runtime_lib()
    includedirs ( KORVLIB_INCLUDES )
end