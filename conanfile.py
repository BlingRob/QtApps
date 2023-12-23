#! /usr/bin/env python
# -*- coding: utf-8 -*-

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
import os

class QtApplication(ConanFile):
    name = 'QtApplication'

    settings = [
        'os',
        "compiler",
        'arch',
        'build_type',
    ]

    generators = [
        "CMakeToolchain", "CMakeDeps"
    ]

    def layout(self):
        cmake_layout(self)

    def config_options(self) -> None:
        self.options['qt'].shared = True

    def requirements(self) -> None:
        self.requires('qt/6.6.0')
        self.requires("brotli/1.1.0", override=True)

    def build(self) -> None:
        cmake: CMake = CMake(self)

        cmake.configure()
        cmake.build()

    def imports(self) -> None:
        self.copy('*.dll', dst=os.path.join(self.package_folder, "lib"), src='bin')
        self.copy('*.so', dst=os.path.join(self.package_folder, "lib"), src='lib')
        self.copy('*.dylib', dst=os.path.join(self.package_folder, "lib"), src='lib')
        self.copy('platforms/*', dst='', src='res/archdatadir/plugins')
