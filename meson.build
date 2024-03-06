project('employee_database', 'cpp', default_options : ['cpp_std=c++17'])

incdir = [include_directories('src')]
catch_dep = dependency('catch2-with-main')

compile_src_files = [
    'main.cpp',
    'Database.cpp',
    'Employee.cpp',
    'UserInterface.cpp',
]
src_dir = 'src'
compile_path_src = []
foreach file : compile_src_files
  compile_path_src += src_dir / file
endforeach

project_name = 'employee_database'
executable(project_name, sources : compile_path_src, include_directories : incdir, dependencies : catch_dep)


compile_src_files = [
    'Database.cpp',
    'Employee.cpp',
    'UserInterface.cpp',
]
src_dir = 'src'
compile_path_src = []
foreach file : compile_src_files
  compile_path_src += src_dir / file
endforeach

tests_path_src = []
foreach file : compile_src_files
  tests_path_src += src_dir / file
endforeach

test_files = [
    'main.cpp',
    'EmployeeTest.cpp',
    'DatabaseTest.cpp',
    'UserInterfaceTest.cpp'
]

tests_dir = 'tests'
foreach file : test_files
  tests_path_src += tests_dir / file
endforeach

exe = executable('unit_tests', tests_path_src, include_directories : incdir, dependencies : catch_dep)
test('unit_tests', exe)