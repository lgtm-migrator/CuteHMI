#ifndef H_EXTENSIONS_CUTEHMI_GUI_1_INCLUDE_CUTEHMI_GUI_FONTS_HPP
#define H_EXTENSIONS_CUTEHMI_GUI_1_INCLUDE_CUTEHMI_GUI_FONTS_HPP

#include "internal/common.hpp"

#include <QObject>
#include <QFont>
#include <QQmlEngine>

namespace cutehmi {
namespace gui {

class CUTEHMI_GUI_API Fonts:
	public QObject
{
		Q_OBJECT
		QML_NAMED_ELEMENT(Fonts)

	public:
		/**
		  Monospace font.
		  */
		Q_PROPERTY(QFont monospace READ monospace WRITE setMonospace NOTIFY monospaceChanged RESET resetMonospace)

		/**
		  Standard font.
		  */
		Q_PROPERTY(QFont standard READ standard WRITE setStandard NOTIFY standardChanged RESET resetStandard)

		Fonts(QObject * parent = nullptr);

		QFont monospace() const;

		void setMonospace(QFont monospace);

		void resetMonospace();

		QFont standard() const;

		void setStandard(QFont standard);

		void resetStandard();

	signals:
		void monospaceChanged();

		void standardChanged();

	protected:
		QFont & DefaultMonospace();

		QFont & DefaultStandard();

	private:
		struct Members {
			QFont monospace;
			QFont standard;
		};

		MPtr<Members> m;

};

}
}

#endif

//(c)C: Copyright © 2020-2022, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: SPDX-License-Identifier: LGPL-3.0-or-later OR MIT
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
//(c)C: Additionally, this file is licensed under terms of MIT license as expressed below.
//(c)C: Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//(c)C: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//(c)C: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
