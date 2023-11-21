project(
    'trading',
    'cpp',
    default_options: [
        'warning_level=3',
        'cpp_std=c++20'
    ]    
)

project_description = 'A trading library'

build_args = [
  '-DPROJECT_NAME=' + meson.project_name(),
  '-DPROJECT_VERSION=' + meson.project_version(),
]

boost_dep = dependency('boost', modules : ['unit_test_framework'])

subdir('include')
subdir('src')
subdir('test')

project_target = library(
    meson.project_name(),
    sources,
    c_args: build_args,
    version: '0.0.1',
    include_directories: inc)

project_dep = declare_dependency (
    include_directories: inc,
    link_with: project_target
)

test(
    'all_tests',
    executable(
        'run_tests',
        test_sources,
        install: false,
        include_directories: inc,
        dependencies : [ project_dep, boost_dep ]
    )
)
