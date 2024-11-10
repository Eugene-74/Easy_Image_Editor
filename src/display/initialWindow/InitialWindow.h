#pragma once
#include <QMainWindow>
#include <QApplication>
#include <QScreen>
#include <QVBoxLayout>

#include "../../structure/imagesData/ImagesData.h"
#include "../../structure/data/Data.h"

#include "../../display/imageEditor/ImageEditor.h"

class InitialWindow : public QMainWindow {
    Q_OBJECT

public:
    InitialWindow();
    qreal pixelRatio;
    QSize screenGeometry;

    void createImageEditor(Data data);
    void clearImageEditor();

protected:
    // void resizeEvent(ImagesData& imagesData) override;

private:
    // Data* data;
    // ImageEditor* imageEditor; // Déclarer un pointeur vers ImageEditor
    // ImageEditor imageEditor;

};