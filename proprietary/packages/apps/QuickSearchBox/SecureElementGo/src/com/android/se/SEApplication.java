/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.se;

import android.app.Application;
import android.content.Intent;
import android.os.SystemProperties;

/**
 * Starts the SecureElementService.
 */
public class SEApplication extends Application {
    private static final String RSC_TYPE = "ro.boot.rsc.ago";

    @Override
    public void onCreate() {
        super.onCreate();

        String value;
    	value = SystemProperties.get(RSC_TYPE, "1g");
        if(!value.contains("512")){
            Intent serviceIntent = new Intent(getApplicationContext(), SecureElementService.class);
            startService(serviceIntent);
        }
    }
}