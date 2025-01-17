// SPDX-License-Identifier: GPL-2.0
#ifndef FILTERMODELS_H
#define FILTERMODELS_H

#include "divetripmodel.h"

#include <QSortFilterProxyModel>

class MultiFilterSortModel : public QSortFilterProxyModel {
	Q_OBJECT
public:
	static MultiFilterSortModel *instance();
	bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
	bool lessThan(const QModelIndex &, const QModelIndex &) const override;

	void resetModel(DiveTripModelBase::Layout layout);
signals:
	void selectionChanged(const QVector<QModelIndex> &indexes);
	void currentDiveChanged(QModelIndex index);
private slots:
	void selectionChangedSlot(const QVector<QModelIndex> &indexes);
	void currentDiveChangedSlot(QModelIndex index);
private:
	MultiFilterSortModel(QObject *parent = 0);
};

#endif
