from setuptools import find_packages, setup

package_name = 'my_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ricardo',
    maintainer_email='ricardo@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	"py_node = my_py_pkg.my_first_node:main",
        	"publisher = my_py_pkg.publisher:main",
        	"subscriber = my_py_pkg.subscriber:main",
        	"add_two_ints_server = my_py_pkg.add_two_ints_server:main",
        	"add_two_ints_client = my_py_pkg.add_two_ints_client:main", 
        	"number_publisher = my_py_pkg.number_publisher:main" 
        ],
    },
)
