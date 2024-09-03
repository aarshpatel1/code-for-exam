package com.example.bolditalicunderlinebuttons;

import android.graphics.Typeface;
import android.os.Bundle;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.style.StyleSpan;
import android.text.style.UnderlineSpan;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private TextView textView;
    private boolean isBold = false;
    private boolean isItalic = false;
    private boolean isUnderlined = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        Button btnBold = findViewById(R.id.btnBold);
        Button btnItalic = findViewById(R.id.btnItalic);
        Button btnUnderline = findViewById(R.id.btnUnderline);

        btnBold.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isBold = !isBold;
                updateTextStyle();
            }
        });

        btnItalic.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isItalic = !isItalic;
                updateTextStyle();
            }
        });

        btnUnderline.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                isUnderlined = !isUnderlined;
                updateTextStyle();
            }
        });
    }

    private void updateTextStyle() {
        SpannableString spannable = new SpannableString(textView.getText());

        // Clear all existing style spans
        StyleSpan[] styleSpans = spannable.getSpans(0, spannable.length(), StyleSpan.class);
        for (StyleSpan span : styleSpans) {
            spannable.removeSpan(span);
        }

        // Clear all existing underline spans
        UnderlineSpan[] underlineSpans = spannable.getSpans(0, spannable.length(), UnderlineSpan.class);
        for (UnderlineSpan span : underlineSpans) {
            spannable.removeSpan(span);
        }

        // Apply bold if selected
        if (isBold) {
            spannable.setSpan(new StyleSpan(Typeface.BOLD), 0, spannable.length(),
                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }

        // Apply italic if selected
        if (isItalic) {
            spannable.setSpan(new StyleSpan(Typeface.ITALIC), 0, spannable.length(),
                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }

        // Apply underline if selected
        if (isUnderlined) {
            spannable.setSpan(new UnderlineSpan(), 0, spannable.length(),
                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
        }

        textView.setText(spannable);
    }
}
