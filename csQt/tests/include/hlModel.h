#ifndef HLMODEL_H
#define HLMODEL_H

#include <QtCore/QAbstractListModel>
#include <QtCore/QVector>

struct hl {
  QString text;
  int line;
  QVector<int> start;
  QVector<int> length;
};

class hlModel : public QAbstractListModel {
  Q_OBJECT
public:
  hlModel(QObject *parent = nullptr);
  ~hlModel();

  void setHighlights(const QVector<hl>& hl);

  QVariant data(const QModelIndex& index, int role) const;
  Qt::ItemFlags flags(const QModelIndex& index) const;
  int rowCount(const QModelIndex& parent) const;

private:
  QVector<hl> _hl{};
};

#endif // HLMODEL_H
