#include "ClickableLabel.h"
ClickableLabel::ClickableLabel(Data* data, const QString& imagePath, QWidget* parent, QSize size, bool setSize, int thumbnail, bool square)
    : QLabel(parent) {

    QImage qImage = data->loadImage(this, imagePath.toStdString(), size, setSize, thumbnail, true, square);

    if (!qImage.isNull()) {
        this->setPixmap(QPixmap::fromImage(qImage).scaled(size - QSize(5, 5), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else {
        this->setText("Erreur");
    }

    if (setSize)
        setFixedSize(size);
    else {

        QSize scaledSize = qImage.size();
        scaledSize.scale(size, Qt::KeepAspectRatio);
        setFixedSize(scaledSize);
    }
    this->setAlignment(Qt::AlignCenter);

    setMouseTracking(true);

    updateStyleSheet();

}

void ClickableLabel::enterEvent(QEvent* event) {
    QLabel::enterEvent(event);
}

void ClickableLabel::leaveEvent(QEvent* event) {
    QLabel::leaveEvent(event);
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {

    if (event->button() == Qt::LeftButton) {

        hover_background_color = CLICK_BACKGROUND_COLOR;

        updateStyleSheet();

    }
    QLabel::mousePressEvent(event);

}

void ClickableLabel::mouseReleaseEvent(QMouseEvent* event) {
    emit clicked();
    if (event->button() == Qt::LeftButton) {
        emit leftClicked();
        hover_background_color = HOVER_BACKGROUND_COLOR;
        updateStyleSheet();
    }
    QLabel::mouseReleaseEvent(event);
}

void ClickableLabel::updateStyleSheet() {
    QString styleSheet = QString(R"(
        QLabel {
            border: %1px solid %3;
            border-radius: %2px;
            background-color: %5;
        }
        QLabel:hover {
            border: %1px solid %4;
            border-radius: %2px;
            background-color: %6; 
        }
        QLabel:disabled {
            background-color: rgba(200, 200, 200, 1);

        }
    )").arg(border).arg(border_radius).arg(border_color).arg(hover_border_color).arg(background_color).arg(hover_background_color);
    this->setStyleSheet(styleSheet);
}