#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>

#include <QtCreator/HighlightingItemDelegate.h>

#include "hlModel.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  QListView *view = new QListView();
  view->setAlternatingRowColors(true);
  view->setEditTriggers(QAbstractItemView::NoEditTriggers);

  hlModel *model = new hlModel(view);
  view->setModel(model);

  QtCreator::HighlightingItemDelegate *delegate = new QtCreator::HighlightingItemDelegate(2, view);
  view->setItemDelegate(delegate);

  QVector<hl> hl;
  hl.push_back({QStringLiteral("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 1, {3, 26}, {3, 7}});
  hl.push_back({QStringLiteral("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 2, {7}, {5}});
  hl.push_back({QStringLiteral("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 3, {10}, {4}});
  model->setHighlights(hl);

  view->setWindowTitle(QStringLiteral("Highlights"));
  view->setGeometry(100, 100, 640, 480);
  view->show();

  const int result = app.exec();
  delete view;

  return result;
}
