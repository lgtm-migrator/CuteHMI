#ifndef H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_ABSTRACTWRITER_HPP
#define H_EXTENSIONS_CUTEHMI_DATAACQUISITION_0_INCLUDE_CUTEHMI_DATAACQUISITION_ABSTRACTWRITER_HPP

#include "TagValue.hpp"
#include "Schema.hpp"

#include <cutehmi/services/Serviceable.hpp>

//<CuteHMI.Workarounds.Qt5Compatibility-1.workaround target="Qt" cause="Qt5">
#include <cutehmi/workarounds/qt5compatibility/qsizetype.hpp>
//</CuteHMI.Workarounds.Qt5Compatibility-1.workaround>

#include <QObject>
#include <QQmlListProperty>
#include <QQmlEngine>

namespace cutehmi {
namespace dataacquisition {

class AbstractWriterAttachedType;

/**
 * Abstract database writer.
 */
class CUTEHMI_DATAACQUISITION_API AbstractWriter:
	public QObject,
	public cutehmi::services::Serviceable
{
		Q_OBJECT
		QML_ATTACHED(cutehmi::dataacquisition::AbstractWriterAttachedType)
		QML_NAMED_ELEMENT(AbstractWriter)
		QML_UNCREATABLE("AbstractWriter is an abstract class")

		friend class AbstractWriterAttachedType;

	public:
		Q_PROPERTY(QQmlListProperty<cutehmi::dataacquisition::TagValue> values READ valueList CONSTANT)
		Q_CLASSINFO("DefaultProperty", "values")

		Q_PROPERTY(cutehmi::dataacquisition::Schema * schema READ schema WRITE setSchema NOTIFY schemaChanged)

		AbstractWriter(QObject * parent = nullptr);

		static cutehmi::dataacquisition::AbstractWriterAttachedType * qmlAttachedProperties(QObject * object);

		QQmlListProperty<TagValue> valueList();

		Schema * schema() const;

		void setSchema(Schema * schema);

		Q_INVOKABLE cutehmi::dataacquisition::TagValue * getValue(int index);

		Q_INVOKABLE void appendValue(cutehmi::dataacquisition::TagValue * value);

		Q_INVOKABLE void clearValues();

	signals:
		void schemaChanged();

	protected:
		typedef QList<TagValue *> TagValueContainer;

		Q_SIGNAL void broke();

		Q_SIGNAL void started();

		Q_SIGNAL void stopped();

		Q_SIGNAL void databaseConnected();

		Q_SIGNAL void schemaValidated();

		virtual void onValueAppend(TagValue * value) = 0;

		virtual void onValueRemove(TagValue * value) = 0;

		const TagValueContainer & values() const;

	private slots:
		void onSchemaValidated(bool result);

	private:
		//<CuteHMI.Workarounds.Qt5Compatibility-1.workaround target="Qt" cause="Qt5">
		static workarounds::qt5compatibility::sizeType ValueListCount(QQmlListProperty<TagValue> * property);

		static TagValue * ValueListAt(QQmlListProperty<TagValue> * property, workarounds::qt5compatibility::sizeType index);
		//</CuteHMI.DataAcquisition-2.workaround target="Qt" cause="Qt5">

		static void ValueListClear(QQmlListProperty<TagValue> * property);

		static void ValuesListAppend(QQmlListProperty<TagValue> * property, TagValue * value);

		struct Members
		{
			TagValueContainer values;
			QQmlListProperty<TagValue> valueList;
			Schema * schema;

			Members(AbstractWriter * p_parent):
				valueList(p_parent, & values, & AbstractWriter::ValuesListAppend, & AbstractWriter::ValueListCount, & AbstractWriter::ValueListAt, & AbstractWriter::ValueListClear),
				schema(nullptr)
			{
			}
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
