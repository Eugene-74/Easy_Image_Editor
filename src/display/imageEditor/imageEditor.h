#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>
#include <QScreen>
#include <QMessageBox>
#include <QTimer>
#include <iostream>
#include <QPushButton>
#include <QResizeEvent>
#include <QSize>
#include <QGraphicsOpacityEffect>
#include <QPointer>


#include <opencv2/opencv.hpp>

#include "../../main.h"
#include "../../structure/imagesData/imagesData.h"
#include "../../structure/data/data.h"
#include "../../display/box/box.h"
#include "../../const.h"



class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(const QString& i, QWidget* parent = nullptr, QSize size = QSize(0, 0));

signals:
    void clicked();  // Signal émis lors du clic

protected:
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;   // Override mouse press event
    void mouseReleaseEvent(QMouseEvent* event) override;  // Override mouse release event




private:
    QPixmap defaultPixmap;


    int border = 0;
    int border_radius = 5;

public:
    void updateStyleSheet();

    QString background_color = "transparent";
    QString hover_background_color = "#b3b3b3";
};

class ImageEditor : public QMainWindow {
    Q_OBJECT

public:

    // Constructor
    ImageEditor(Data& a, QWidget* parent = nullptr);   // Initialize the reference member

    ~ImageEditor() {}

    void reload();
    void reloadMainImage();

    void setImage(ImageData& imageData);

    void nextImage();
    void previousImage();
    void rotateLeft();
    void rotateRight();
    void updatePreview();
    void updateButtons();
    void createButtons();
    void clearWindow();


    ClickableLabel* createImageDelete();


protected:
    // void resizeEvent(ImagesData& imagesData) override;


private:
    // ImagesData& imagesData;
    QLabel* imageLabel; // Pour afficher l'image
    QVBoxLayout* mainLayout;
    QHBoxLayout* previewButtonLayout;
    QHBoxLayout* actionButtonLayout;
    QHBoxLayout* buttonLayout;
    QSize previewSize;
    QSize actionSize;
    QSize screenGeometry;
    Data data;
    qreal pixelRatio;

    ClickableLabel* buttonImageBefore;
    ClickableLabel* buttonImageNext;

    ClickableLabel* imageRotateRight;
    ClickableLabel* imageRotateLeft;
    ClickableLabel* imageDelete;
    ClickableLabel* imageSave;





};



