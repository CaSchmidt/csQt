/****************************************************************************
** Copyright (c) 2013-2014, Carsten Schmidt. All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its
**    contributors may be used to endorse or promote products derived from
**    this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef CSQTUTIL_H
#define CSQTUTIL_H

#include <QtCore/QLocale>
#include <QtCore/QMetaEnum>
#include <QtCore/QModelIndex>
#include <QtCore/QRect>
#include <QtCore/QRectF>
#include <QtCore/QString>
#include <QtWidgets/QWidget>

#include <csQt/csqt_config.h>
#include <csQt/csNamespace.h>

#ifndef _L1C
# define _L1C(c)  QChar::fromLatin1(c)
#endif

class QAbstractItemView;
class QColor;
class QPoint;
class QTableView;
class QVariant;
class QWidget;

template<typename QEnumT>
inline const char *csEnumText(const QEnumT& value)
{
  return QMetaEnum::fromType<QEnumT>().valueToKey(value);
}

template<typename T>
inline T *csFindParentWidget(QWidget *widget)
{
  if( widget == nullptr ) {
    return nullptr;
  }

  while( (widget = widget->parentWidget()) != nullptr ) {
    if( dynamic_cast<T*>(widget) != nullptr ) {
      return dynamic_cast<T*>(widget);
    }
  }

  return nullptr;
}

inline qreal csScale(const QSizeF& from, const QSizeF& to)
{
  const qreal sh = to.width() /from.width();
  const qreal sv = to.height()/from.height();
  return from.height()*sh > to.height()
      ? sv
      : sh;
}

CS_QT_EXPORT int csIndexDepth(const QModelIndex& index);

CS_QT_EXPORT QPoint csMapToGlobal(const QAbstractItemView *view, const QPoint& p);

CS_QT_EXPORT QRect csScreenGeometry(const QPoint& globalPos, QWidget *widget);

CS_QT_EXPORT int csScreenNumber(const QPoint& globalPos, QWidget *widget);

CS_QT_EXPORT void csSetBackgroundColor(QWidget *w, const QColor& c,
                                       const bool inactive = true);

CS_QT_EXPORT void csSetClipboardText(const QString& text);

CS_QT_EXPORT void csSetClipboardText(const QStringList& list, const QString& _sep = QString());

CS_QT_EXPORT QString csTableToString(const QTableView *table,
                                     const QModelIndex& topLeft = QModelIndex(),
                                     const QModelIndex& bottomRight = QModelIndex(),
                                     const int role = Qt::DisplayRole,
                                     const cs::TableExtractionFlags flags = cs::NoTableExtractionFlags);

CS_QT_EXPORT QString csVariantToString(const QVariant& variant,
                                       const QLocale& locale = QLocale(),
                                       const char format = 'g', const int precision = 6);

#endif // CSQTUTIL_H
