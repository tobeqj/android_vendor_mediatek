// This source code is generated by UdpGeneratorTool, not recommend to modify it directly
package com.mediatek.location.lppe.bluetooth;

import com.mediatek.socket.base.SocketUtils.BaseBuffer;
import com.mediatek.socket.base.SocketUtils.Codable;

public class BluetoothRTD implements Codable {

    public final static BluetoothRTD _instance = new BluetoothRTD();

    /**
     * 0..16777215 <br>
     */
    public int value = 0;
    public BluetoothRTDUnit unit = BluetoothRTDUnit.microseconds;
    /**
     * 0..255 <br>
     */
    public short accuracy = (short) 0;

    public boolean equals(Object _obj) {
        if (_obj == null) {
            return false;
        }
        if (_obj == this) {
            return true;
        }
        if (!(_obj instanceof BluetoothRTD)) {
            return false;
        }

        BluetoothRTD _tmp = (BluetoothRTD) _obj;
        if (_tmp.value != value)
            return false;
        if (!_tmp.unit.equals(unit))
            return false;
        if (_tmp.accuracy != accuracy)
            return false;
        return true;
    }

    public String toString() {
        StringBuilder _o = new StringBuilder();
        _o.append("BluetoothRTD ");
        _o.append("value=[" + value + "] ");
        _o.append("unit=[" + unit + "] ");
        _o.append("accuracy=[" + accuracy + "] ");
        return _o.toString();
    }

    @Override
    public void encode(BaseBuffer _buff) {
        _buff.putInt(value);
        _buff.putCodable(unit);
        _buff.putShort(accuracy);
    }

    @Override
    public BluetoothRTD decode(BaseBuffer _buff) {
        BluetoothRTD _out = new BluetoothRTD();
        _out.value = _buff.getInt();
        _out.unit = (BluetoothRTDUnit) _buff.getCodable(BluetoothRTDUnit._instance);
        _out.accuracy = _buff.getShort();
        return _out;
    }

    @Override
    public BluetoothRTD[] getArray(Codable[] data) {
        BluetoothRTD[] _out = new BluetoothRTD[data.length];
        for (int _i = 0; _i < data.length; _i++) {
            _out[_i] = (BluetoothRTD) data[_i];
        }
        return _out;
    }

}