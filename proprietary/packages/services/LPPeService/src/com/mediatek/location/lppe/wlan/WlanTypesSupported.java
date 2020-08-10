// This source code is generated by UdpGeneratorTool, not recommend to modify it directly
package com.mediatek.location.lppe.wlan;

import com.mediatek.socket.base.SocketUtils.BaseBuffer;
import com.mediatek.socket.base.SocketUtils.Codable;

public class WlanTypesSupported implements Codable {

    public final static WlanTypesSupported _instance = new WlanTypesSupported();

    public boolean ieee802_11a = false;
    public boolean ieee802_11b = false;
    public boolean ieee802_11g = false;
    public boolean ieee802_11n = false;
    public boolean ieee802_11ac = false;
    public boolean ieee802_11ad = false;

    public boolean equals(Object _obj) {
        if (_obj == null) {
            return false;
        }
        if (_obj == this) {
            return true;
        }
        if (!(_obj instanceof WlanTypesSupported)) {
            return false;
        }

        WlanTypesSupported _tmp = (WlanTypesSupported) _obj;
        if (_tmp.ieee802_11a != ieee802_11a)
            return false;
        if (_tmp.ieee802_11b != ieee802_11b)
            return false;
        if (_tmp.ieee802_11g != ieee802_11g)
            return false;
        if (_tmp.ieee802_11n != ieee802_11n)
            return false;
        if (_tmp.ieee802_11ac != ieee802_11ac)
            return false;
        if (_tmp.ieee802_11ad != ieee802_11ad)
            return false;
        return true;
    }

    public String toString() {
        StringBuilder _o = new StringBuilder();
        _o.append("WlanTypesSupported ");
        _o.append("ieee802_11a=[" + ieee802_11a + "] ");
        _o.append("ieee802_11b=[" + ieee802_11b + "] ");
        _o.append("ieee802_11g=[" + ieee802_11g + "] ");
        _o.append("ieee802_11n=[" + ieee802_11n + "] ");
        _o.append("ieee802_11ac=[" + ieee802_11ac + "] ");
        _o.append("ieee802_11ad=[" + ieee802_11ad + "] ");
        return _o.toString();
    }

    @Override
    public void encode(BaseBuffer _buff) {
        _buff.putBool(ieee802_11a);
        _buff.putBool(ieee802_11b);
        _buff.putBool(ieee802_11g);
        _buff.putBool(ieee802_11n);
        _buff.putBool(ieee802_11ac);
        _buff.putBool(ieee802_11ad);
    }

    @Override
    public WlanTypesSupported decode(BaseBuffer _buff) {
        WlanTypesSupported _out = new WlanTypesSupported();
        _out.ieee802_11a = _buff.getBool();
        _out.ieee802_11b = _buff.getBool();
        _out.ieee802_11g = _buff.getBool();
        _out.ieee802_11n = _buff.getBool();
        _out.ieee802_11ac = _buff.getBool();
        _out.ieee802_11ad = _buff.getBool();
        return _out;
    }

    @Override
    public WlanTypesSupported[] getArray(Codable[] data) {
        WlanTypesSupported[] _out = new WlanTypesSupported[data.length];
        for (int _i = 0; _i < data.length; _i++) {
            _out[_i] = (WlanTypesSupported) data[_i];
        }
        return _out;
    }

}