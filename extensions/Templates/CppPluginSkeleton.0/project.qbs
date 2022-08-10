import qbs

import cutehmi

Project {
	name: "Templates.CppPluginSkeleton.0"

	references: [
		"tests/tests.qbs"
	]

	cutehmi.CppExtension {
		name: parent.name

		vendor: "The Secret Order of Templates"

		domain: "xn--cuthmi-5of.kde.org"

		friendlyName: "C++ Plugin Skeleton"

		description: "Skeletal C++ extension with QML plugin."

		files: [
			"README.md",
			"LICENSE.MIT",
			"LICENSE.LGPL3",
			"include/templates/cpppluginskeleton/Exception.hpp",
			"include/templates/cpppluginskeleton/Init.hpp",
			"include/templates/cpppluginskeleton/internal/platform.hpp",
			"include/templates/cpppluginskeleton/internal/common.hpp",
			"include/templates/cpppluginskeleton/logging.hpp",
			"include/templates/cpppluginskeleton/metadata.hpp",
			"src/templates/cpppluginskeleton/Init.cpp",
			"src/templates/cpppluginskeleton/internal/QMLPlugin.cpp",
			"src/templates/cpppluginskeleton/internal/QMLPlugin.hpp",
			"src/templates/cpppluginskeleton/logging.cpp",
		]

		Depends { name: "CuteHMI.2" }

		Depends { name: "cutehmi.doxygen" }
		cutehmi.doxygen.warnIfUndocumented: false
		cutehmi.doxygen.exclude: ['tests']

		Depends { name: "cutehmi.qmldir" }

		Depends { name: "cutehmi.qmltyperegistrar" }

		Depends { name: "cutehmi.skeleton.cpp" }
		cutehmi.skeleton.cpp.generateQMLPlugin: true
		cutehmi.skeleton.cpp.generateException: true
		cutehmi.skeleton.cpp.generateInit: true

		Export {
			Depends { name: "CuteHMI.2" }
		}
	}
}

//(c)ANYONE: Copyright © 2020-2022, Anyone. All rights reserved.
//(c)ANYONE: SPDX-License-Identifier: LGPL-3.0-or-later OR MIT
//(c)ANYONE: This file is a part of CuteHMI.
//(c)ANYONE: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)ANYONE: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)ANYONE: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
//(c)ANYONE: Additionally, this file is licensed under terms of MIT license as expressed below.
//(c)ANYONE: Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//(c)ANYONE: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//(c)ANYONE: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
