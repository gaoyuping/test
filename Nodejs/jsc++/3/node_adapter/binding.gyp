{
    "targets": [{
        "target_name": "testaddon",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "Adapter.cc",
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "<!(node -e \"require('nan')\")",
            "lib/include",
        ],
        'libraries': [
        '-LibForNode.lib',
        '-lws2_32.lib',
        '-lwldap32.lib'
        ],
        'library_dirs': [
        'lib/lib'
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        'configurations': {
        'Debug': {
            'msvs_settings': {
                'VCCLCompilerTool': {
                    'RuntimeLibrary': 3, # 3 /MDd
                },
            },
        },
        'Release': {
            'msvs_settings': {
                'VCCLCompilerTool': {
                    'RuntimeLibrary': 4, # 4 /MD
                },
            },
        }
        },
    }]
}