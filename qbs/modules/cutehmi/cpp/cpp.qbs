/**
  This module provides common C++ settings to be used accross Product items.
  */
Module {
//<qbs-cutehmi.cpp-1.workaround target="Qbs" cuase="missing">
// Qbs does not allow Export within Module items. Because of that modules can not export C++ include paths. Workaround is to provide
// a property containing include paths to export (which can be accessed by Module items) and use this property in a product export.
	/**
	  List of include paths to be exported by a product.
	  */
	property stringList exportedIncludePaths: []
//</qbs-cutehmi.cpp-1.workaround>

	Depends { name: "cpp" }

	Properties {
		condition: qbs.buildVariant.contains("debug")
		cpp.defines: outer.concat(["QT_QML_DEBUG"])
	}

	Properties {
		condition: !qbs.buildVariant.contains("debug")
		cpp.defines: outer.concat(["CUTEHMI_NDEBUG", "QT_NO_DEBUG_OUTPUT"])
	}

	Properties {
		condition: qbs.targetOS.contains("linux")
		cpp.linkerFlags: ["--no-undefined"]
	}

	cpp.defines: ["QT_DEPRECATED_WARNINGS"]

	cpp.cxxLanguageVersion: "c++17"
}

//(c)C: Copyright © 2019-2022, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: SPDX-License-Identifier: LGPL-3.0-or-later OR MIT
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
//(c)C: Additionally, this file is licensed under terms of MIT license as expressed below.
//(c)C: Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//(c)C: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//(c)C: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
