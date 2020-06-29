#include <QtCreator/HighlightingItemDelegate.h>

#include "hlModel.h"

////// public ////////////////////////////////////////////////////////////////

hlModel::hlModel(QObject *parent)
  : QAbstractListModel(parent)
{
}

hlModel::~hlModel()
{
}

void hlModel::setHighlights(const QVector<hl>& hl)
{
  beginResetModel();
  _hl = hl;
  endResetModel();
}

QVariant hlModel::data(const QModelIndex& index, int role) const
{
  using namespace QtCreator;
  if( !index.isValid() ) {
    return QVariant();
  }
  const int row = index.row();
  if( role == Qt::DisplayRole ) {
    return _hl[row].text;
  } else if( role == int(HighlightingItemRole::LineNumber) ) {
    return _hl[row].line;
  } else if( role == int(HighlightingItemRole::StartColumn) ) {
    return QVariant::fromValue(_hl[row].start);
  } else if( role == int(HighlightingItemRole::Length) ) {
    return QVariant::fromValue(_hl[row].length);
  } else if( role == int(HighlightingItemRole::Foreground) ) {
    return QColor(Qt::black);
  } else if( role == int(HighlightingItemRole::Background) ) {
    return QColor(Qt::yellow);
  }
  return QVariant();
}

Qt::ItemFlags hlModel::flags(const QModelIndex& index) const
{
  return QAbstractListModel::flags(index);
}

int hlModel::rowCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return _hl.size();
}
