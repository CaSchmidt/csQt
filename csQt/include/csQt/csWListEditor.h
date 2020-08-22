/****************************************************************************
** Copyright (c) 2020, Carsten Schmidt. All rights reserved.
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

#ifndef WLISTEDITOR_H
#define WLISTEDITOR_H

#include <QtWidgets/QWidget>

#include <csQt/csqt_config.h>

class QListView;
class QPushButton;

namespace Ui {
  class csWListEditor;
} // namespace Ui

class CS_QT_EXPORT csWListEditor : public QWidget {
  Q_OBJECT
public:
  csWListEditor(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  ~csWListEditor();

private slots:
  virtual void onAdd();
  virtual void onDown();
  virtual void onRemove();
  virtual void onUp();

protected:
  enum Button {
    Add = 0,
    Down,
    Remove,
    Up
  };

  const QPushButton *button(const Button id) const;
  QPushButton *button(const Button id);
  const QListView *view() const;
  QListView *view();

private:
  Ui::csWListEditor *ui{nullptr};
};

#endif // WLISTEDITOR_H
