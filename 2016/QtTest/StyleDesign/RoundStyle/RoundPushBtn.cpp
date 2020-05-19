////////////////////////////////////////////////////////////
/// LampPushBtn.cpp
///
/// Created on: 2005-10-23
///      Author: lcf_2
///////////////////////////////////////////////////////////

#include <QtGui/QtGui>

#include "RoundPushBtn.h"


/// ���캯��
CRoundPushBtn::CRoundPushBtn(QWidget* parent)
 :	QPushButton(parent),
	m_Stat(StatUnknown)
{
	ini();
}


void CRoundPushBtn::ini()
{

	/// ���ð�ť��С
	int nLampSz = 28;
	setMinimumSize(nLampSz, nLampSz);
	setMaximumSize(nLampSz, nLampSz);


	/// �������
	setCheckable(true);
	setChecked(true);
	setFlat(true);
	setEnabled(false);
}

/// ���õƵ�״̬
void CRoundPushBtn::setUIState(IndnStat nState)
{
	m_Stat	= nState;
	update();
}
