/****************************************************************************
** Copyright (c) 2019, Carsten Schmidt. All rights reserved.
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

#include <QtWidgets/QPushButton>

#include "csQt/csDialogButtonBox.h"

////// Public ////////////////////////////////////////////////////////////////

CS_QT_EXPORT QPushButton *csAddButton(QDialogButtonBox *box, const QString& text,
                                      const QDialogButtonBox::ButtonRole role,
                                      const bool set_auto_default,
                                      const bool set_default)
{
  QPushButton *pb = box->addButton(text, role);
  pb->setAutoDefault(set_auto_default);
  pb->setDefault(set_default);
  return pb;
}

CS_QT_EXPORT bool csRemoveAllButtons(QDialogButtonBox *box)
{
  const QList<QAbstractButton*> buttons = box->buttons();
  for(QAbstractButton *button : buttons) {
    box->removeButton(button);
    delete button;
  }
  return box->buttons().isEmpty();
}

CS_QT_EXPORT void csRemoveDefaults(QDialogButtonBox *box, const bool disconnect)
{
  const QList<QAbstractButton*> buttons = box->buttons();
  for(QAbstractButton *button : buttons) {
    QPushButton *pb = dynamic_cast<QPushButton*>(button);
    if( pb == nullptr ) {
      continue;
    }
    if( disconnect ) {
      pb->disconnect();
    }
    pb->setAutoDefault(false);
    pb->setDefault(false);
  }
}
