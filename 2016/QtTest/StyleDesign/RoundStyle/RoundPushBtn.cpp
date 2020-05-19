////////////////////////////////////////////////////////////
/// LampPushBtn.cpp
///
/// Created on: 2005-10-23
///      Author: lcf_2
///////////////////////////////////////////////////////////

#include <QtGui/QtGui>

#include "RoundPushBtn.h"


/// 构造函数
CRoundPushBtn::CRoundPushBtn(QWidget* parent)
 :	QPushButton(parent),
	m_Stat(StatUnknown)
{
	ini();
}


void CRoundPushBtn::ini()
{

	/// 设置按钮大小
	int nLampSz = 28;
	setMinimumSize(nLampSz, nLampSz);
	setMaximumSize(nLampSz, nLampSz);


	/// 设置外观
	setCheckable(true);
	setChecked(true);
	setFlat(true);
	setEnabled(false);
}

/// 设置灯的状态
void CRoundPushBtn::setUIState(IndnStat nState)
{
	m_Stat	= nState;
	update();
}
