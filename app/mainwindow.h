#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <interleaf.h>
#include <object.h>
#include <QGroupBox>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTreeView>

#include "objectmodel.h"
#include "panel.h"
#include "vector3edit.h"
#include "viewer/mediapanel.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);

  void OpenFilename(const QString &s);

signals:

private:
  void InitializeMenuBar();

  void SetPanel(Panel *panel, si::Object *chunk);

  void ExtractObject(si::Object *obj);
  void ReplaceObject(si::Object *obj);

  static bool OpenInterleafFileInternal(QWidget *parent, si::Interleaf *interleaf, const QString &s);

  QString GetOpenFileName();

  static const QString kFileFilter;

  QStackedWidget *config_stack_;

  QTreeView *tree_;

  QGroupBox *action_grp_;

  Panel *panel_blank_;
  MediaPanel *panel_media_;

  ObjectModel model_;
  si::Interleaf interleaf_;

  si::Object *last_set_data_;

  QString current_filename_;

  QGroupBox *properties_group_;

  QLineEdit *m_extraEdit;
  Vector3Edit *m_LocationEdit;
  Vector3Edit *m_UpEdit;

  QSpinBox *start_time_edit_;

private slots:
  void NewFile();
  void OpenFile();
  bool SaveFile();
  bool SaveFileAs();

  void SelectionChanged(const QModelIndex &index);

  void ShowContextMenu(const QPoint &p);

  void ExtractSelectedItems();
  void ExtractClicked();

  void ReplaceClicked();

  void ViewSIFile();

  void ExtraChanged(const QString &v);
  void LocationChanged(const si::Vector3 &v);
  void UpChanged(const si::Vector3 &v);
  void StartTimeChanged(int t);

};

#endif // MAINWINDOW_H
