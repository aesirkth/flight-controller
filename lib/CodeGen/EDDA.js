/* for struct library
The MIT License (MIT)

Copyright (c) 2016 Aksel Jensen (TheRealAksel at github)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*eslint-env es6*/
const rechk = /^([<>])?(([1-9]\d*)?([xcbB?hHiIfdsp]))*$/
const refmt = /([1-9]\d*)?([xcbB?hHiIfdsp])/g
const str = (v,o,c) => String.fromCharCode(
    ...new Uint8Array(v.buffer, v.byteOffset + o, c))
const rts = (v,o,c,s) => new Uint8Array(v.buffer, v.byteOffset + o, c)
    .set(s.split('').map(str => str.charCodeAt(0)))
const pst = (v,o,c) => str(v, o + 1, Math.min(v.getUint8(o), c - 1))
const tsp = (v,o,c,s) => { v.setUint8(o, s.length); rts(v, o + 1, c - 1, s) }
const lut = le => ({
    x: c=>[1,c,0],
    c: c=>[c,1,o=>({u:v=>str(v, o, 1)      , p:(v,c)=>rts(v, o, 1, c)     })],
    '?': c=>[c,1,o=>({u:v=>Boolean(v.getUint8(o)),p:(v,B)=>v.setUint8(o,B)})],
    b: c=>[c,1,o=>({u:v=>v.getInt8(   o   ), p:(v,b)=>v.setInt8(   o,b   )})],
    B: c=>[c,1,o=>({u:v=>v.getUint8(  o   ), p:(v,B)=>v.setUint8(  o,B   )})],
    h: c=>[c,2,o=>({u:v=>v.getInt16(  o,le), p:(v,h)=>v.setInt16(  o,h,le)})],
    H: c=>[c,2,o=>({u:v=>v.getUint16( o,le), p:(v,H)=>v.setUint16( o,H,le)})],
    i: c=>[c,4,o=>({u:v=>v.getInt32(  o,le), p:(v,i)=>v.setInt32(  o,i,le)})],
    I: c=>[c,4,o=>({u:v=>v.getUint32( o,le), p:(v,I)=>v.setUint32( o,I,le)})],
    f: c=>[c,4,o=>({u:v=>v.getFloat32(o,le), p:(v,f)=>v.setFloat32(o,f,le)})],
    d: c=>[c,8,o=>({u:v=>v.getFloat64(o,le), p:(v,d)=>v.setFloat64(o,d,le)})],
    s: c=>[1,c,o=>({u:v=>str(v,o,c), p:(v,s)=>rts(v,o,c,s.slice(0,c    ) )})],
    p: c=>[1,c,o=>({u:v=>pst(v,o,c), p:(v,s)=>tsp(v,o,c,s.slice(0,c - 1) )})]
})
const errbuf = new RangeError("Structure larger than remaining buffer")
const errval = new RangeError("Not enough values for structure")
function struct(format) {
    let fns = [], size = 0, m = rechk.exec(format)
    if (!m) { throw new RangeError("Invalid format string") }
    const t = lut('<' === m[1]), lu = (n, c) => t[c](n ? parseInt(n, 10) : 1)
    while ((m = refmt.exec(format))) { ((r, s, f) => {
        for (let i = 0; i < r; ++i, size += s) { if (f) {fns.push(f(size))} }
    })(...lu(...m.slice(1)))}
    const unpack_from = (arrb, offs) => {
        if (arrb.byteLength < (offs|0) + size) { throw errbuf }
        let v = new DataView(arrb, offs|0)
        return fns.map(f => f.u(v))
    }
    const pack_into = (arrb, offs, ...values) => {
        if (values.length < fns.length) { throw errval }
        if (arrb.byteLength < offs + size) { throw errbuf }
        const v = new DataView(arrb, offs)
        new Uint8Array(arrb, offs, size).fill(0)
        fns.forEach((f, i) => f.p(v, values[i]))
    }
    const pack = (...values) => {
        let b = new ArrayBuffer(size)
        pack_into(b, 0, ...values)
        return b
    }
    const unpack = arrb => unpack_from(arrb, 0)
    function* iter_unpack(arrb) { 
        for (let offs = 0; offs + size <= arrb.byteLength; offs += size) {
            yield unpack_from(arrb, offs);
        }
    }
    return Object.freeze({
        unpack, pack, unpack_from, pack_into, iter_unpack, format, size})
}
//end struct library

/********************************
* GENERATED FILE DO NOT EDIT
********************************/

function scaledFloat_to_uint(value, scale) {
    return value * scale
}

function uint_to_scaledFloat(value, scale) {
    return value / scale
}

function packedFloat_to_uint(value, minValue, maxValue, size) {
    let intMax = (1 << size * 8) - 1
    if(value < minValue)
      return 0
    if(value > maxValue)
      return intMax
    let ratio = (value - minValue) / (maxValue - minValue)
    return 1 + ((intMax - 2)) * ratio
}
  
function uint_to_packedFloat(value, minValue, maxValue, size) {
    let intMax = (1 << size * 8) - 1
    if(value <= 0)
      return minValue - 1.0
    if(value >= intMax)
      return maxValue + 1.0
    let ratio = (value - 1) / (intMax - 2)
    return ratio * (maxValue - minValue) + minValue
}

export const fields = {
    checksum: 0,
    channel: 1,
    system_state: 2,
    output_state: 3,
    edda_signature: 4,
    request: 5,
    response: 6,
    time_s: 7,
    action: 8,
    engine_state: 9,
    uptime_ms: 10,
    destination_node: 11,
    latency_us: 12,
    time_us: 13,
    year: 14,
    month: 15,
    day: 16,
    hour: 17,
    minute: 18,
    second: 19,
    truncated_frame_number: 20,
    edda_controller_ambient_pressure_bar: 21,
    edda_controller_can_rx_time_max_microsecond: 22,
    edda_controller_board_temperature_celsius: 23,
    edda_controller_can_rx_time_microsecond: 24,
    edda_controller_can_rx_time_min_microsecond: 25,
    edda_controller_humidity_sensor_temperature_celsius: 26,
    edda_controller_can_tx_time_max_microsecond: 27,
    edda_controller_can_tx_time_microsecond: 28,
    edda_controller_imu_temperature_celsius: 29,
    edda_controller_can_tx_time_min_microsecond: 30,
    edda_controller_input_current_ampere: 31,
    edda_controller_internal_temperature_celsius: 32,
    edda_controller_input_current_max_ampere: 33,
    edda_controller_input_current_min_ampere: 34,
    edda_controller_pressure_sensor_temperature_celsius: 35,
    edda_controller_input_voltage_max_volt: 36,
    edda_controller_input_voltage_min_volt: 37,
    edda_controller_relative_humidity_percentage: 38,
    edda_controller_input_voltage_volt: 39,
    edda_controller_latency_edda_ground_time_max_millisecond: 40,
    edda_controller_latency_edda_ground_time_min_millisecond: 41,
    edda_controller_latency_edda_temperature_1_time_max_millisecond: 42,
    edda_controller_latency_edda_temperature_1_time_min_millisecond: 43,
    edda_controller_latency_edda_temperature_2_time_max_millisecond: 44,
    edda_controller_latency_edda_temperature_2_time_min_millisecond: 45,
    edda_controller_latency_edda_transducer_time_max_millisecond: 46,
    edda_controller_latency_edda_transducer_time_min_millisecond: 47,
    edda_controller_timing_time_freq_hertz: 48,
    edda_controller_timing_time_max_microsecond: 49,
    edda_controller_timing_time_min_microsecond: 50,
    edda_controller_x_acceleration_max_gforce: 51,
    edda_controller_x_acceleration_min_gforce: 52,
    edda_controller_y_acceleration_max_gforce: 53,
    edda_controller_y_acceleration_min_gforce: 54,
    edda_controller_z_acceleration_max_gforce: 55,
    edda_controller_z_acceleration_min_gforce: 56,
    edda_controller_can_rx_size_rate_byte: 57,
    edda_controller_can_tx_size_rate_byte: 58,
    edda_controller_latency_edda_ground_time_millisecond: 59,
    edda_controller_latency_edda_temperature_1_time_millisecond: 60,
    edda_controller_latency_edda_temperature_2_time_millisecond: 61,
    edda_controller_latency_edda_transducer_time_millisecond: 62,
    edda_controller_timing_time_microsecond: 63,
    edda_controller_x_acceleration_gforce: 64,
    edda_controller_y_acceleration_gforce: 65,
    edda_controller_z_acceleration_gforce: 66,
    sindri_bleed_valve_current_ampere: 67,
    sindri_ignition_current_ampere: 68,
    sindri_main_valve_current_ampere: 69,
    sindri_bleed_valve_estimation_current_ampere: 70,
    sindri_bleed_valve_estimation_power_watt: 71,
    sindri_bleed_valve_estimation_resistance_ohm: 72,
    sindri_bleed_valve_estimation_voltage_volt: 73,
    sindri_bleed_valve_power_watt: 74,
    sindri_bleed_valve_voltage_volt: 75,
    sindri_ignition_estimation_current_ampere: 76,
    sindri_ignition_estimation_power_watt: 77,
    sindri_ignition_estimation_resistance_ohm: 78,
    sindri_ignition_estimation_voltage_volt: 79,
    sindri_ignition_power_watt: 80,
    sindri_ignition_voltage_volt: 81,
    sindri_main_valve_estimation_current_ampere: 82,
    sindri_main_valve_estimation_power_watt: 83,
    sindri_main_valve_estimation_resistance_ohm: 84,
    sindri_main_valve_estimation_voltage_volt: 85,
    sindri_main_valve_power_watt: 86,
    sindri_main_valve_voltage_volt: 87,
    sindri_oxidizer_tank_weight_max_kilogram: 88,
    sindri_oxidizer_tank_weight_min_kilogram: 89,
    sindri_oxidizer_tank_weight_kilogram: 90,
    edda_ground_ambient_pressure_bar: 91,
    edda_ground_can_rx_time_max_microsecond: 92,
    edda_ground_board_temperature_celsius: 93,
    edda_ground_can_rx_time_microsecond: 94,
    edda_ground_can_rx_time_min_microsecond: 95,
    edda_ground_humidity_sensor_temperature_celsius: 96,
    edda_ground_can_tx_time_max_microsecond: 97,
    edda_ground_can_tx_time_microsecond: 98,
    edda_ground_imu_temperature_celsius: 99,
    edda_ground_can_tx_time_min_microsecond: 100,
    edda_ground_input_current_ampere: 101,
    edda_ground_internal_temperature_celsius: 102,
    edda_ground_input_current_max_ampere: 103,
    edda_ground_input_current_min_ampere: 104,
    edda_ground_pressure_sensor_temperature_celsius: 105,
    edda_ground_input_voltage_max_volt: 106,
    edda_ground_input_voltage_min_volt: 107,
    edda_ground_relative_humidity_percentage: 108,
    edda_ground_input_voltage_volt: 109,
    edda_ground_latency_edda_controller_time_max_millisecond: 110,
    edda_ground_latency_edda_controller_time_min_millisecond: 111,
    edda_ground_latency_edda_temperature_1_time_max_millisecond: 112,
    edda_ground_latency_edda_temperature_1_time_min_millisecond: 113,
    edda_ground_latency_edda_temperature_2_time_max_millisecond: 114,
    edda_ground_latency_edda_temperature_2_time_min_millisecond: 115,
    edda_ground_latency_edda_transducer_time_max_millisecond: 116,
    edda_ground_latency_edda_transducer_time_min_millisecond: 117,
    edda_ground_timing_time_freq_hertz: 118,
    edda_ground_timing_time_max_microsecond: 119,
    edda_ground_timing_time_min_microsecond: 120,
    edda_ground_x_acceleration_max_gforce: 121,
    edda_ground_x_acceleration_min_gforce: 122,
    edda_ground_y_acceleration_max_gforce: 123,
    edda_ground_y_acceleration_min_gforce: 124,
    edda_ground_z_acceleration_max_gforce: 125,
    edda_ground_z_acceleration_min_gforce: 126,
    edda_ground_can_rx_size_rate_byte: 127,
    edda_ground_can_tx_size_rate_byte: 128,
    edda_ground_latency_edda_controller_time_millisecond: 129,
    edda_ground_latency_edda_temperature_1_time_millisecond: 130,
    edda_ground_latency_edda_temperature_2_time_millisecond: 131,
    edda_ground_latency_edda_transducer_time_millisecond: 132,
    edda_ground_timing_time_microsecond: 133,
    edda_ground_x_acceleration_gforce: 134,
    edda_ground_y_acceleration_gforce: 135,
    edda_ground_z_acceleration_gforce: 136,
    edda_temperature_1_ambient_pressure_bar: 137,
    edda_temperature_1_can_rx_time_max_microsecond: 138,
    edda_temperature_1_board_temperature_celsius: 139,
    edda_temperature_1_can_rx_time_microsecond: 140,
    edda_temperature_1_can_rx_time_min_microsecond: 141,
    edda_temperature_1_humidity_sensor_temperature_celsius: 142,
    edda_temperature_1_can_tx_time_max_microsecond: 143,
    edda_temperature_1_can_tx_time_microsecond: 144,
    edda_temperature_1_imu_temperature_celsius: 145,
    edda_temperature_1_can_tx_time_min_microsecond: 146,
    edda_temperature_1_input_current_ampere: 147,
    edda_temperature_1_internal_temperature_celsius: 148,
    edda_temperature_1_input_current_max_ampere: 149,
    edda_temperature_1_input_current_min_ampere: 150,
    edda_temperature_1_pressure_sensor_temperature_celsius: 151,
    edda_temperature_1_input_voltage_max_volt: 152,
    edda_temperature_1_input_voltage_min_volt: 153,
    edda_temperature_1_relative_humidity_percentage: 154,
    edda_temperature_1_input_voltage_volt: 155,
    edda_temperature_1_latency_edda_controller_time_max_millisecond: 156,
    edda_temperature_1_latency_edda_controller_time_min_millisecond: 157,
    edda_temperature_1_latency_edda_ground_time_max_millisecond: 158,
    edda_temperature_1_latency_edda_ground_time_min_millisecond: 159,
    edda_temperature_1_latency_edda_temperature_2_time_max_millisecond: 160,
    edda_temperature_1_latency_edda_temperature_2_time_min_millisecond: 161,
    edda_temperature_1_latency_edda_transducer_time_max_millisecond: 162,
    edda_temperature_1_latency_edda_transducer_time_min_millisecond: 163,
    edda_temperature_1_timing_time_freq_hertz: 164,
    edda_temperature_1_timing_time_max_microsecond: 165,
    edda_temperature_1_timing_time_min_microsecond: 166,
    edda_temperature_1_x_acceleration_max_gforce: 167,
    edda_temperature_1_x_acceleration_min_gforce: 168,
    edda_temperature_1_y_acceleration_max_gforce: 169,
    edda_temperature_1_y_acceleration_min_gforce: 170,
    edda_temperature_1_z_acceleration_max_gforce: 171,
    edda_temperature_1_z_acceleration_min_gforce: 172,
    edda_temperature_1_can_rx_size_rate_byte: 173,
    edda_temperature_1_can_tx_size_rate_byte: 174,
    edda_temperature_1_latency_edda_controller_time_millisecond: 175,
    edda_temperature_1_latency_edda_ground_time_millisecond: 176,
    edda_temperature_1_latency_edda_temperature_2_time_millisecond: 177,
    edda_temperature_1_latency_edda_transducer_time_millisecond: 178,
    edda_temperature_1_timing_time_microsecond: 179,
    edda_temperature_1_x_acceleration_gforce: 180,
    edda_temperature_1_y_acceleration_gforce: 181,
    edda_temperature_1_z_acceleration_gforce: 182,
    edda_temperature_1_compensation_0_temperature_celsius: 183,
    edda_temperature_1_compensation_1_temperature_celsius: 184,
    sindri_rtd_01_resistance_ohm: 185,
    sindri_rtd_01_voltage_volt: 186,
    sindri_rtd_02_resistance_ohm: 187,
    sindri_rtd_02_voltage_volt: 188,
    sindri_therm_09_voltage_volt: 189,
    sindri_therm_10_voltage_volt: 190,
    sindri_therm_11_voltage_volt: 191,
    sindri_therm_12_voltage_volt: 192,
    sindri_rtd_01_temperature_celsius: 193,
    sindri_rtd_02_temperature_celsius: 194,
    sindri_therm_09_temperature_celsius: 195,
    sindri_therm_10_temperature_celsius: 196,
    sindri_therm_11_temperature_celsius: 197,
    sindri_therm_12_temperature_celsius: 198,
    edda_temperature_2_ambient_pressure_bar: 199,
    edda_temperature_2_can_rx_time_max_microsecond: 200,
    edda_temperature_2_board_temperature_celsius: 201,
    edda_temperature_2_can_rx_time_microsecond: 202,
    edda_temperature_2_can_rx_time_min_microsecond: 203,
    edda_temperature_2_humidity_sensor_temperature_celsius: 204,
    edda_temperature_2_can_tx_time_max_microsecond: 205,
    edda_temperature_2_can_tx_time_microsecond: 206,
    edda_temperature_2_imu_temperature_celsius: 207,
    edda_temperature_2_can_tx_time_min_microsecond: 208,
    edda_temperature_2_input_current_ampere: 209,
    edda_temperature_2_internal_temperature_celsius: 210,
    edda_temperature_2_input_current_max_ampere: 211,
    edda_temperature_2_input_current_min_ampere: 212,
    edda_temperature_2_pressure_sensor_temperature_celsius: 213,
    edda_temperature_2_input_voltage_max_volt: 214,
    edda_temperature_2_input_voltage_min_volt: 215,
    edda_temperature_2_relative_humidity_percentage: 216,
    edda_temperature_2_input_voltage_volt: 217,
    edda_temperature_2_latency_edda_controller_time_max_millisecond: 218,
    edda_temperature_2_latency_edda_controller_time_min_millisecond: 219,
    edda_temperature_2_latency_edda_ground_time_max_millisecond: 220,
    edda_temperature_2_latency_edda_ground_time_min_millisecond: 221,
    edda_temperature_2_latency_edda_temperature_1_time_max_millisecond: 222,
    edda_temperature_2_latency_edda_temperature_1_time_min_millisecond: 223,
    edda_temperature_2_latency_edda_transducer_time_max_millisecond: 224,
    edda_temperature_2_latency_edda_transducer_time_min_millisecond: 225,
    edda_temperature_2_timing_time_freq_hertz: 226,
    edda_temperature_2_timing_time_max_microsecond: 227,
    edda_temperature_2_timing_time_min_microsecond: 228,
    edda_temperature_2_x_acceleration_max_gforce: 229,
    edda_temperature_2_x_acceleration_min_gforce: 230,
    edda_temperature_2_y_acceleration_max_gforce: 231,
    edda_temperature_2_y_acceleration_min_gforce: 232,
    edda_temperature_2_z_acceleration_max_gforce: 233,
    edda_temperature_2_z_acceleration_min_gforce: 234,
    edda_temperature_2_can_rx_size_rate_byte: 235,
    edda_temperature_2_can_tx_size_rate_byte: 236,
    edda_temperature_2_latency_edda_controller_time_millisecond: 237,
    edda_temperature_2_latency_edda_ground_time_millisecond: 238,
    edda_temperature_2_latency_edda_temperature_1_time_millisecond: 239,
    edda_temperature_2_latency_edda_transducer_time_millisecond: 240,
    edda_temperature_2_timing_time_microsecond: 241,
    edda_temperature_2_x_acceleration_gforce: 242,
    edda_temperature_2_y_acceleration_gforce: 243,
    edda_temperature_2_z_acceleration_gforce: 244,
    edda_temperature_2_compensation_0_temperature_celsius: 245,
    edda_temperature_2_compensation_1_temperature_celsius: 246,
    sindri_therm_01_temperature_celsius: 247,
    sindri_therm_02_temperature_celsius: 248,
    sindri_therm_03_temperature_celsius: 249,
    sindri_therm_04_temperature_celsius: 250,
    sindri_therm_05_temperature_celsius: 251,
    sindri_therm_06_temperature_celsius: 252,
    sindri_therm_07_temperature_celsius: 253,
    sindri_therm_08_temperature_celsius: 254,
    sindri_therm_01_voltage_volt: 255,
    sindri_therm_02_voltage_volt: 256,
    sindri_therm_03_voltage_volt: 257,
    sindri_therm_04_voltage_volt: 258,
    sindri_therm_05_voltage_volt: 259,
    sindri_therm_06_voltage_volt: 260,
    sindri_therm_07_voltage_volt: 261,
    sindri_therm_08_voltage_volt: 262,
    edda_transducer_ambient_pressure_bar: 263,
    edda_transducer_can_rx_time_max_microsecond: 264,
    edda_transducer_board_temperature_celsius: 265,
    edda_transducer_can_rx_time_microsecond: 266,
    edda_transducer_can_rx_time_min_microsecond: 267,
    edda_transducer_humidity_sensor_temperature_celsius: 268,
    edda_transducer_can_tx_time_max_microsecond: 269,
    edda_transducer_can_tx_time_microsecond: 270,
    edda_transducer_imu_temperature_celsius: 271,
    edda_transducer_can_tx_time_min_microsecond: 272,
    edda_transducer_input_current_ampere: 273,
    edda_transducer_internal_temperature_celsius: 274,
    edda_transducer_input_current_max_ampere: 275,
    edda_transducer_input_current_min_ampere: 276,
    edda_transducer_pressure_sensor_temperature_celsius: 277,
    edda_transducer_input_voltage_max_volt: 278,
    edda_transducer_input_voltage_min_volt: 279,
    edda_transducer_relative_humidity_percentage: 280,
    edda_transducer_input_voltage_volt: 281,
    edda_transducer_latency_edda_controller_time_max_millisecond: 282,
    edda_transducer_latency_edda_controller_time_min_millisecond: 283,
    edda_transducer_latency_edda_ground_time_max_millisecond: 284,
    edda_transducer_latency_edda_ground_time_min_millisecond: 285,
    edda_transducer_latency_edda_temperature_1_time_max_millisecond: 286,
    edda_transducer_latency_edda_temperature_1_time_min_millisecond: 287,
    edda_transducer_latency_edda_temperature_2_time_max_millisecond: 288,
    edda_transducer_latency_edda_temperature_2_time_min_millisecond: 289,
    edda_transducer_timing_time_freq_hertz: 290,
    edda_transducer_timing_time_max_microsecond: 291,
    edda_transducer_timing_time_min_microsecond: 292,
    edda_transducer_x_acceleration_max_gforce: 293,
    edda_transducer_x_acceleration_min_gforce: 294,
    edda_transducer_y_acceleration_max_gforce: 295,
    edda_transducer_y_acceleration_min_gforce: 296,
    edda_transducer_z_acceleration_max_gforce: 297,
    edda_transducer_z_acceleration_min_gforce: 298,
    edda_transducer_can_rx_size_rate_byte: 299,
    edda_transducer_can_tx_size_rate_byte: 300,
    edda_transducer_latency_edda_controller_time_millisecond: 301,
    edda_transducer_latency_edda_ground_time_millisecond: 302,
    edda_transducer_latency_edda_temperature_1_time_millisecond: 303,
    edda_transducer_latency_edda_temperature_2_time_millisecond: 304,
    edda_transducer_timing_time_microsecond: 305,
    edda_transducer_x_acceleration_gforce: 306,
    edda_transducer_y_acceleration_gforce: 307,
    edda_transducer_z_acceleration_gforce: 308,
    sindri_transducer_01_pressure_bar: 309,
    sindri_transducer_04_pressure_bar: 310,
    sindri_transducer_01_pressure_max_bar: 311,
    sindri_transducer_01_pressure_min_bar: 312,
    sindri_transducer_02_pressure_max_bar: 313,
    sindri_transducer_02_pressure_min_bar: 314,
    sindri_transducer_03_pressure_max_bar: 315,
    sindri_transducer_03_pressure_min_bar: 316,
    sindri_transducer_04_pressure_max_bar: 317,
    sindri_transducer_04_pressure_min_bar: 318,
    sindri_transducer_01_voltage_volt: 319,
    sindri_transducer_02_voltage_volt: 320,
    sindri_transducer_03_voltage_volt: 321,
    sindri_transducer_04_voltage_volt: 322,
    sindri_transducer_05_voltage_volt: 323,
    sindri_transducer_06_voltage_volt: 324,
    sindri_transducer_02_pressure_bar: 325,
    sindri_transducer_03_pressure_bar: 326,
    sindri_transducer_12v_voltage_volt: 327,
    sindri_transducer_5v_voltage_volt: 328,
    frame_number: 329,
    time_since_boot_ms: 330,
}
export const messages = {
    ChannelState: 0,
    ChannelTransitionRequest: 1,
    ChannelTransitionResponse: 2,
    Countdown: 3,
    EngineActionRequest: 4,
    EngineActionResponse: 5,
    EngineState: 6,
    Heartbeat: 7,
    Latency: 8,
    Ping: 9,
    Pong: 10,
    RtcDate: 11,
    RtcTime: 12,
    Telemetry__ControllerBoard_edda_controller_00: 13,
    Telemetry__ControllerBoard_edda_controller_01: 14,
    Telemetry__ControllerBoard_edda_controller_02: 15,
    Telemetry__ControllerBoard_edda_controller_03: 16,
    Telemetry__ControllerBoard_edda_controller_04: 17,
    Telemetry__ControllerBoard_edda_controller_05: 18,
    Telemetry__ControllerBoard_edda_controller_06: 19,
    Telemetry__ControllerBoard_edda_controller_07: 20,
    Telemetry__ControllerBoard_edda_controller_08: 21,
    Telemetry__ControllerBoard_edda_controller_09: 22,
    Telemetry__ControllerBoard_edda_controller_10: 23,
    Telemetry__ControllerBoard_edda_controller_11: 24,
    Telemetry__ControllerBoard_edda_controller_12: 25,
    Telemetry__ControllerBoard_edda_controller_13: 26,
    Telemetry__ControllerBoard_edda_controller_14: 27,
    Telemetry__ControllerBoard_edda_controller_15: 28,
    Telemetry__ControllerBoard_edda_controller_16: 29,
    Telemetry__ControllerBoard_edda_controller_17: 30,
    Telemetry__ControllerBoard_edda_controller_18: 31,
    Telemetry__ControllerBoard_edda_controller_19: 32,
    Telemetry__ControllerBoard_sindri_00: 33,
    Telemetry__ControllerBoard_sindri_01: 34,
    Telemetry__ControllerBoard_sindri_02: 35,
    Telemetry__ControllerBoard_sindri_03: 36,
    Telemetry__ControllerBoard_sindri_04: 37,
    Telemetry__ControllerBoard_sindri_05: 38,
    Telemetry__ControllerBoard_sindri_06: 39,
    Telemetry__ControllerBoard_sindri_07: 40,
    Telemetry__ControllerBoard_sindri_08: 41,
    Telemetry__ControllerBoard_sindri_09: 42,
    Telemetry__ControllerBoard_sindri_10: 43,
    Telemetry__ControllerBoard_sindri_11: 44,
    Telemetry__ControllerBoard_sindri_12: 45,
    Telemetry__GroundController_edda_ground_00: 46,
    Telemetry__GroundController_edda_ground_01: 47,
    Telemetry__GroundController_edda_ground_02: 48,
    Telemetry__GroundController_edda_ground_03: 49,
    Telemetry__GroundController_edda_ground_04: 50,
    Telemetry__GroundController_edda_ground_05: 51,
    Telemetry__GroundController_edda_ground_06: 52,
    Telemetry__GroundController_edda_ground_07: 53,
    Telemetry__GroundController_edda_ground_08: 54,
    Telemetry__GroundController_edda_ground_09: 55,
    Telemetry__GroundController_edda_ground_10: 56,
    Telemetry__GroundController_edda_ground_11: 57,
    Telemetry__GroundController_edda_ground_12: 58,
    Telemetry__GroundController_edda_ground_13: 59,
    Telemetry__GroundController_edda_ground_14: 60,
    Telemetry__GroundController_edda_ground_15: 61,
    Telemetry__GroundController_edda_ground_16: 62,
    Telemetry__GroundController_edda_ground_17: 63,
    Telemetry__GroundController_edda_ground_18: 64,
    Telemetry__GroundController_edda_ground_19: 65,
    Telemetry__TemperatureBoard1_edda_temperature_1_00: 66,
    Telemetry__TemperatureBoard1_edda_temperature_1_01: 67,
    Telemetry__TemperatureBoard1_edda_temperature_1_02: 68,
    Telemetry__TemperatureBoard1_edda_temperature_1_03: 69,
    Telemetry__TemperatureBoard1_edda_temperature_1_04: 70,
    Telemetry__TemperatureBoard1_edda_temperature_1_05: 71,
    Telemetry__TemperatureBoard1_edda_temperature_1_06: 72,
    Telemetry__TemperatureBoard1_edda_temperature_1_07: 73,
    Telemetry__TemperatureBoard1_edda_temperature_1_08: 74,
    Telemetry__TemperatureBoard1_edda_temperature_1_09: 75,
    Telemetry__TemperatureBoard1_edda_temperature_1_10: 76,
    Telemetry__TemperatureBoard1_edda_temperature_1_11: 77,
    Telemetry__TemperatureBoard1_edda_temperature_1_12: 78,
    Telemetry__TemperatureBoard1_edda_temperature_1_13: 79,
    Telemetry__TemperatureBoard1_edda_temperature_1_14: 80,
    Telemetry__TemperatureBoard1_edda_temperature_1_15: 81,
    Telemetry__TemperatureBoard1_edda_temperature_1_16: 82,
    Telemetry__TemperatureBoard1_edda_temperature_1_17: 83,
    Telemetry__TemperatureBoard1_edda_temperature_1_18: 84,
    Telemetry__TemperatureBoard1_edda_temperature_1_19: 85,
    Telemetry__TemperatureBoard1_edda_temperature_1_20: 86,
    Telemetry__TemperatureBoard1_sindri_00: 87,
    Telemetry__TemperatureBoard1_sindri_01: 88,
    Telemetry__TemperatureBoard1_sindri_02: 89,
    Telemetry__TemperatureBoard1_sindri_03: 90,
    Telemetry__TemperatureBoard1_sindri_04: 91,
    Telemetry__TemperatureBoard1_sindri_05: 92,
    Telemetry__TemperatureBoard1_sindri_06: 93,
    Telemetry__TemperatureBoard2_edda_temperature_2_00: 94,
    Telemetry__TemperatureBoard2_edda_temperature_2_01: 95,
    Telemetry__TemperatureBoard2_edda_temperature_2_02: 96,
    Telemetry__TemperatureBoard2_edda_temperature_2_03: 97,
    Telemetry__TemperatureBoard2_edda_temperature_2_04: 98,
    Telemetry__TemperatureBoard2_edda_temperature_2_05: 99,
    Telemetry__TemperatureBoard2_edda_temperature_2_06: 100,
    Telemetry__TemperatureBoard2_edda_temperature_2_07: 101,
    Telemetry__TemperatureBoard2_edda_temperature_2_08: 102,
    Telemetry__TemperatureBoard2_edda_temperature_2_09: 103,
    Telemetry__TemperatureBoard2_edda_temperature_2_10: 104,
    Telemetry__TemperatureBoard2_edda_temperature_2_11: 105,
    Telemetry__TemperatureBoard2_edda_temperature_2_12: 106,
    Telemetry__TemperatureBoard2_edda_temperature_2_13: 107,
    Telemetry__TemperatureBoard2_edda_temperature_2_14: 108,
    Telemetry__TemperatureBoard2_edda_temperature_2_15: 109,
    Telemetry__TemperatureBoard2_edda_temperature_2_16: 110,
    Telemetry__TemperatureBoard2_edda_temperature_2_17: 111,
    Telemetry__TemperatureBoard2_edda_temperature_2_18: 112,
    Telemetry__TemperatureBoard2_edda_temperature_2_19: 113,
    Telemetry__TemperatureBoard2_edda_temperature_2_20: 114,
    Telemetry__TemperatureBoard2_sindri_00: 115,
    Telemetry__TemperatureBoard2_sindri_01: 116,
    Telemetry__TemperatureBoard2_sindri_02: 117,
    Telemetry__TemperatureBoard2_sindri_03: 118,
    Telemetry__TemperatureBoard2_sindri_04: 119,
    Telemetry__TemperatureBoard2_sindri_05: 120,
    Telemetry__TemperatureBoard2_sindri_06: 121,
    Telemetry__TemperatureBoard2_sindri_07: 122,
    Telemetry__TransducerBoard_edda_transducer_00: 123,
    Telemetry__TransducerBoard_edda_transducer_01: 124,
    Telemetry__TransducerBoard_edda_transducer_02: 125,
    Telemetry__TransducerBoard_edda_transducer_03: 126,
    Telemetry__TransducerBoard_edda_transducer_04: 127,
    Telemetry__TransducerBoard_edda_transducer_05: 128,
    Telemetry__TransducerBoard_edda_transducer_06: 129,
    Telemetry__TransducerBoard_edda_transducer_07: 130,
    Telemetry__TransducerBoard_edda_transducer_08: 131,
    Telemetry__TransducerBoard_edda_transducer_09: 132,
    Telemetry__TransducerBoard_edda_transducer_10: 133,
    Telemetry__TransducerBoard_edda_transducer_11: 134,
    Telemetry__TransducerBoard_edda_transducer_12: 135,
    Telemetry__TransducerBoard_edda_transducer_13: 136,
    Telemetry__TransducerBoard_edda_transducer_14: 137,
    Telemetry__TransducerBoard_edda_transducer_15: 138,
    Telemetry__TransducerBoard_edda_transducer_16: 139,
    Telemetry__TransducerBoard_edda_transducer_17: 140,
    Telemetry__TransducerBoard_edda_transducer_18: 141,
    Telemetry__TransducerBoard_edda_transducer_19: 142,
    Telemetry__TransducerBoard_sindri_00: 143,
    Telemetry__TransducerBoard_sindri_01: 144,
    Telemetry__TransducerBoard_sindri_02: 145,
    Telemetry__TransducerBoard_sindri_03: 146,
    Telemetry__TransducerBoard_sindri_04: 147,
    Telemetry__TransducerBoard_sindri_05: 148,
    Telemetry__TransducerBoard_sindri_06: 149,
    Telemetry__TransducerBoard_sindri_07: 150,
    Telemetry__TransducerBoard_sindri_08: 151,
    Telemetry__TransducerBoard_sindri_09: 152,
    TelemetryMetaFrame: 153,
    TelemetryMetaTime: 154,
}
export const categories = {
    none: 0,
}
export const nodes = {
    Controller_Board: 48,
    Ground_Controller: 1,
    Power_Channel_1: 241,
    Power_Channel_2: 242,
    Power_Channel_3: 243,
    Temperature_Board_1: 17,
    Temperature_Board_2: 18,
    Transducer_Board: 32,
}
export const Channel = {
    Ignition: 0,
    BleedValve: 1,
    MainValve: 2,
}
export const ChannelSystemState = {
    Idle: 0,
    Arming: 1,
    Armed: 2,
    Firing: 3,
}
export const ChannelOutputState = {
    Grounded: 0,
    ResistanceMeasurement: 1,
    High: 2,
}
export const ChannelTransition = {
    Arm: 0,
    Disarm: 1,
    Fire: 2,
    StopFire: 3,
}
export const ChannelTransitionResult = {
    Success: 0,
    Failure: 1,
}
export const EngineAction = {
    Ignition: 0,
    EnableManualControl: 1,
    DisableManualControl: 2,
}
export const EngineTransitionResult = {
    Success: 0,
    Failure: 1,
}
export const EngineState = {
    Unknown: 0,
    Idle: 1,
    PartialArmed: 2,
    Armed: 3,
    Firing: 4,
    ManualControl: 5,
}
export const EddaNodes = {
    ControllerBoard: 48,
    GroundController: 1,
    PowerChannel1: 241,
    PowerChannel2: 242,
    PowerChannel3: 243,
    TemperatureBoard1: 17,
    TemperatureBoard2: 18,
    TransducerBoard: 32,
    Undefined: 255,
    XiyaoStuff: 64,
}
export class ChannelState_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.ChannelState
        this._category = categories.none
        this._id = 35
        this._size = 5
        this._checksum = 0
        this._channel = 0
        this._system_state = 0
        this._output_state = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_channel(value) {
        this._channel = value.value
    }
    set_system_state(value) {
        this._system_state = value.value
    }
    set_output_state(value) {
        this._output_state = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._channel)
        index += 1
        struct("<B").pack_into(buf, index, this._system_state)
        index += 1
        struct("<B").pack_into(buf, index, this._output_state)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_channel() {
        return Channel(this._channel)
    }
    get_system_state() {
        return ChannelSystemState(this._system_state)
    }
    get_output_state() {
        return ChannelOutputState(this._output_state)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.channel, value: this.get_channel()})
        data.push({field: fields.system_state, value: this.get_system_state()})
        data.push({field: fields.output_state, value: this.get_output_state()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._channel = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._system_state = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._output_state = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class ChannelTransitionRequest_from_Ground_Controller_to_Controller_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Controller_Board
        this._message = messages.ChannelTransitionRequest
        this._category = categories.none
        this._id = 33
        this._size = 6
        this._checksum = 0
        this._edda_signature = 0
        this._channel = 0
        this._request = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_edda_signature(value) {
        this._edda_signature = value
    }
    set_channel(value) {
        this._channel = value.value
    }
    set_request(value) {
        this._request = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_signature)
        index += 2
        struct("<B").pack_into(buf, index, this._channel)
        index += 1
        struct("<B").pack_into(buf, index, this._request)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_edda_signature() {
        return this._edda_signature
    }
    get_channel() {
        return Channel(this._channel)
    }
    get_request() {
        return ChannelTransition(this._request)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.edda_signature, value: this.get_edda_signature()})
        data.push({field: fields.channel, value: this.get_channel()})
        data.push({field: fields.request, value: this.get_request()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_signature = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._channel = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._request = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class ChannelTransitionResponse_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.ChannelTransitionResponse
        this._category = categories.none
        this._id = 34
        this._size = 7
        this._checksum = 0
        this._edda_signature = 0
        this._channel = 0
        this._request = 0
        this._response = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_edda_signature(value) {
        this._edda_signature = value
    }
    set_channel(value) {
        this._channel = value.value
    }
    set_request(value) {
        this._request = value.value
    }
    set_response(value) {
        this._response = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_signature)
        index += 2
        struct("<B").pack_into(buf, index, this._channel)
        index += 1
        struct("<B").pack_into(buf, index, this._request)
        index += 1
        struct("<B").pack_into(buf, index, this._response)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_edda_signature() {
        return this._edda_signature
    }
    get_channel() {
        return Channel(this._channel)
    }
    get_request() {
        return ChannelTransition(this._request)
    }
    get_response() {
        return ChannelTransitionResult(this._response)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.edda_signature, value: this.get_edda_signature()})
        data.push({field: fields.channel, value: this.get_channel()})
        data.push({field: fields.request, value: this.get_request()})
        data.push({field: fields.response, value: this.get_response()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_signature = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._channel = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._request = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._response = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Countdown_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Countdown
        this._category = categories.none
        this._id = 36
        this._size = 6
        this._checksum = 0
        this._time_s = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_time_s(value) {
        this._time_s = packedFloat_to_uint(value, -3600, 7200, 4)
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._time_s)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_time_s() {
        return uint_to_scaledFloat(this._time_s, -3600, 7200, 4)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.time_s, value: this.get_time_s()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._time_s = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class EngineActionRequest_from_Ground_Controller_to_Controller_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Controller_Board
        this._message = messages.EngineActionRequest
        this._category = categories.none
        this._id = 38
        this._size = 5
        this._checksum = 0
        this._edda_signature = 0
        this._action = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_edda_signature(value) {
        this._edda_signature = value
    }
    set_action(value) {
        this._action = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_signature)
        index += 2
        struct("<B").pack_into(buf, index, this._action)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_edda_signature() {
        return this._edda_signature
    }
    get_action() {
        return EngineAction(this._action)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.edda_signature, value: this.get_edda_signature()})
        data.push({field: fields.action, value: this.get_action()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_signature = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._action = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class EngineActionResponse_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.EngineActionResponse
        this._category = categories.none
        this._id = 39
        this._size = 6
        this._checksum = 0
        this._edda_signature = 0
        this._action = 0
        this._response = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_edda_signature(value) {
        this._edda_signature = value
    }
    set_action(value) {
        this._action = value.value
    }
    set_response(value) {
        this._response = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_signature)
        index += 2
        struct("<B").pack_into(buf, index, this._action)
        index += 1
        struct("<B").pack_into(buf, index, this._response)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_edda_signature() {
        return this._edda_signature
    }
    get_action() {
        return EngineAction(this._action)
    }
    get_response() {
        return EngineTransitionResult(this._response)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.edda_signature, value: this.get_edda_signature()})
        data.push({field: fields.action, value: this.get_action()})
        data.push({field: fields.response, value: this.get_response()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_signature = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._action = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._response = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class EngineState_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.EngineState
        this._category = categories.none
        this._id = 37
        this._size = 3
        this._checksum = 0
        this._engine_state = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_engine_state(value) {
        this._engine_state = value.value
    }
    build_buf() {
        let buf = new ArrayBuffer(3)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._engine_state)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_engine_state() {
        return EngineState(this._engine_state)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.engine_state, value: this.get_engine_state()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._engine_state = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Heartbeat_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 0
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 4
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Power_Channel_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Power_Channel_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 5
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Power_Channel_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Power_Channel_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 6
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Power_Channel_3_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Power_Channel_3
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 7
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 1
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 2
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Heartbeat_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Heartbeat
        this._category = categories.none
        this._id = 3
        this._size = 6
        this._checksum = 0
        this._uptime_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_uptime_ms(value) {
        this._uptime_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<L").pack_into(buf, index, this._uptime_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_uptime_ms() {
        return this._uptime_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.uptime_ms, value: this.get_uptime_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._uptime_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Latency_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Latency
        this._category = categories.none
        this._id = 18
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._latency_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_latency_us(value) {
        this._latency_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._latency_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_latency_us() {
        return this._latency_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.latency_us, value: this.get_latency_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._latency_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Latency_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Latency
        this._category = categories.none
        this._id = 22
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._latency_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_latency_us(value) {
        this._latency_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._latency_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_latency_us() {
        return this._latency_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.latency_us, value: this.get_latency_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._latency_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Latency_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Latency
        this._category = categories.none
        this._id = 19
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._latency_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_latency_us(value) {
        this._latency_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._latency_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_latency_us() {
        return this._latency_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.latency_us, value: this.get_latency_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._latency_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Latency_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Latency
        this._category = categories.none
        this._id = 20
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._latency_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_latency_us(value) {
        this._latency_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._latency_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_latency_us() {
        return this._latency_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.latency_us, value: this.get_latency_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._latency_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Latency_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Latency
        this._category = categories.none
        this._id = 21
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._latency_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_latency_us(value) {
        this._latency_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._latency_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_latency_us() {
        return this._latency_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.latency_us, value: this.get_latency_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._latency_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Controller_Board_to_Controller_Board {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Controller_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 8
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Controller_Board_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Ping
        this._category = categories.none
        this._id = 8
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Controller_Board_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Ping
        this._category = categories.none
        this._id = 8
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Controller_Board_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Transducer_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 8
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Ping
        this._category = categories.none
        this._id = 8
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Ground_Controller_to_Controller_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Controller_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 12
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Ground_Controller_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Ping
        this._category = categories.none
        this._id = 12
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Ground_Controller_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Ping
        this._category = categories.none
        this._id = 12
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Ground_Controller_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Transducer_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 12
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Ping
        this._category = categories.none
        this._id = 12
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_1_to_Controller_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Controller_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 9
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_1_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Ping
        this._category = categories.none
        this._id = 9
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_1_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Ping
        this._category = categories.none
        this._id = 9
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_1_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Transducer_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 9
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Ping
        this._category = categories.none
        this._id = 9
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_2_to_Controller_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Controller_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 10
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_2_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Ping
        this._category = categories.none
        this._id = 10
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_2_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Ping
        this._category = categories.none
        this._id = 10
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_2_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Transducer_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 10
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Ping
        this._category = categories.none
        this._id = 10
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Transducer_Board_to_Controller_Board {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Controller_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 11
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Transducer_Board_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Ping
        this._category = categories.none
        this._id = 11
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Transducer_Board_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Ping
        this._category = categories.none
        this._id = 11
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Transducer_Board_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Transducer_Board
        this._message = messages.Ping
        this._category = categories.none
        this._id = 11
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Ping_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Ping
        this._category = categories.none
        this._id = 11
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Controller_Board_to_Controller_Board {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Controller_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 13
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Controller_Board_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Pong
        this._category = categories.none
        this._id = 13
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Controller_Board_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Pong
        this._category = categories.none
        this._id = 13
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Controller_Board_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Transducer_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 13
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Pong
        this._category = categories.none
        this._id = 13
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Ground_Controller_to_Controller_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Controller_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 17
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Ground_Controller_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Pong
        this._category = categories.none
        this._id = 17
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Ground_Controller_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Pong
        this._category = categories.none
        this._id = 17
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Ground_Controller_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Transducer_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 17
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Pong
        this._category = categories.none
        this._id = 17
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_1_to_Controller_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Controller_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 14
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_1_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Pong
        this._category = categories.none
        this._id = 14
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_1_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Pong
        this._category = categories.none
        this._id = 14
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_1_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Transducer_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 14
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Pong
        this._category = categories.none
        this._id = 14
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_2_to_Controller_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Controller_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 15
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_2_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Pong
        this._category = categories.none
        this._id = 15
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_2_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Pong
        this._category = categories.none
        this._id = 15
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_2_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Transducer_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 15
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Pong
        this._category = categories.none
        this._id = 15
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Transducer_Board_to_Controller_Board {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Controller_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 16
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Transducer_Board_to_Temperature_Board_1 {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Temperature_Board_1
        this._message = messages.Pong
        this._category = categories.none
        this._id = 16
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Transducer_Board_to_Temperature_Board_2 {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Temperature_Board_2
        this._message = messages.Pong
        this._category = categories.none
        this._id = 16
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Transducer_Board_to_Transducer_Board {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Transducer_Board
        this._message = messages.Pong
        this._category = categories.none
        this._id = 16
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class Pong_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Pong
        this._category = categories.none
        this._id = 16
        this._size = 7
        this._checksum = 0
        this._destination_node = 0
        this._time_us = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_destination_node(value) {
        this._destination_node = value.value
    }
    set_time_us(value) {
        this._time_us = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._destination_node)
        index += 1
        struct("<L").pack_into(buf, index, this._time_us)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_destination_node() {
        return EddaNodes(this._destination_node)
    }
    get_time_us() {
        return this._time_us
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.destination_node, value: this.get_destination_node()})
        data.push({field: fields.time_us, value: this.get_time_us()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._destination_node = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_us = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class RtcDate_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcDate
        this._category = categories.none
        this._id = 23
        this._size = 6
        this._checksum = 0
        this._year = 0
        this._month = 0
        this._day = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_year(value) {
        this._year = value
    }
    set_month(value) {
        this._month = value
    }
    set_day(value) {
        this._day = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._year)
        index += 2
        struct("<B").pack_into(buf, index, this._month)
        index += 1
        struct("<B").pack_into(buf, index, this._day)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_year() {
        return this._year
    }
    get_month() {
        return this._month
    }
    get_day() {
        return this._day
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.year, value: this.get_year()})
        data.push({field: fields.month, value: this.get_month()})
        data.push({field: fields.day, value: this.get_day()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._year = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._month = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._day = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcDate_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcDate
        this._category = categories.none
        this._id = 27
        this._size = 6
        this._checksum = 0
        this._year = 0
        this._month = 0
        this._day = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_year(value) {
        this._year = value
    }
    set_month(value) {
        this._month = value
    }
    set_day(value) {
        this._day = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._year)
        index += 2
        struct("<B").pack_into(buf, index, this._month)
        index += 1
        struct("<B").pack_into(buf, index, this._day)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_year() {
        return this._year
    }
    get_month() {
        return this._month
    }
    get_day() {
        return this._day
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.year, value: this.get_year()})
        data.push({field: fields.month, value: this.get_month()})
        data.push({field: fields.day, value: this.get_day()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._year = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._month = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._day = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcDate_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcDate
        this._category = categories.none
        this._id = 24
        this._size = 6
        this._checksum = 0
        this._year = 0
        this._month = 0
        this._day = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_year(value) {
        this._year = value
    }
    set_month(value) {
        this._month = value
    }
    set_day(value) {
        this._day = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._year)
        index += 2
        struct("<B").pack_into(buf, index, this._month)
        index += 1
        struct("<B").pack_into(buf, index, this._day)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_year() {
        return this._year
    }
    get_month() {
        return this._month
    }
    get_day() {
        return this._day
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.year, value: this.get_year()})
        data.push({field: fields.month, value: this.get_month()})
        data.push({field: fields.day, value: this.get_day()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._year = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._month = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._day = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcDate_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcDate
        this._category = categories.none
        this._id = 25
        this._size = 6
        this._checksum = 0
        this._year = 0
        this._month = 0
        this._day = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_year(value) {
        this._year = value
    }
    set_month(value) {
        this._month = value
    }
    set_day(value) {
        this._day = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._year)
        index += 2
        struct("<B").pack_into(buf, index, this._month)
        index += 1
        struct("<B").pack_into(buf, index, this._day)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_year() {
        return this._year
    }
    get_month() {
        return this._month
    }
    get_day() {
        return this._day
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.year, value: this.get_year()})
        data.push({field: fields.month, value: this.get_month()})
        data.push({field: fields.day, value: this.get_day()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._year = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._month = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._day = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcDate_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcDate
        this._category = categories.none
        this._id = 26
        this._size = 6
        this._checksum = 0
        this._year = 0
        this._month = 0
        this._day = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_year(value) {
        this._year = value
    }
    set_month(value) {
        this._month = value
    }
    set_day(value) {
        this._day = value
    }
    build_buf() {
        let buf = new ArrayBuffer(6)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<H").pack_into(buf, index, this._year)
        index += 2
        struct("<B").pack_into(buf, index, this._month)
        index += 1
        struct("<B").pack_into(buf, index, this._day)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_year() {
        return this._year
    }
    get_month() {
        return this._month
    }
    get_day() {
        return this._day
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.year, value: this.get_year()})
        data.push({field: fields.month, value: this.get_month()})
        data.push({field: fields.day, value: this.get_day()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._year = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._month = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._day = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcTime_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcTime
        this._category = categories.none
        this._id = 28
        this._size = 5
        this._checksum = 0
        this._hour = 0
        this._minute = 0
        this._second = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_hour(value) {
        this._hour = value
    }
    set_minute(value) {
        this._minute = value
    }
    set_second(value) {
        this._second = value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._hour)
        index += 1
        struct("<B").pack_into(buf, index, this._minute)
        index += 1
        struct("<B").pack_into(buf, index, this._second)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_hour() {
        return this._hour
    }
    get_minute() {
        return this._minute
    }
    get_second() {
        return this._second
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.hour, value: this.get_hour()})
        data.push({field: fields.minute, value: this.get_minute()})
        data.push({field: fields.second, value: this.get_second()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._hour = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._minute = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._second = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcTime_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcTime
        this._category = categories.none
        this._id = 32
        this._size = 5
        this._checksum = 0
        this._hour = 0
        this._minute = 0
        this._second = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_hour(value) {
        this._hour = value
    }
    set_minute(value) {
        this._minute = value
    }
    set_second(value) {
        this._second = value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._hour)
        index += 1
        struct("<B").pack_into(buf, index, this._minute)
        index += 1
        struct("<B").pack_into(buf, index, this._second)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_hour() {
        return this._hour
    }
    get_minute() {
        return this._minute
    }
    get_second() {
        return this._second
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.hour, value: this.get_hour()})
        data.push({field: fields.minute, value: this.get_minute()})
        data.push({field: fields.second, value: this.get_second()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._hour = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._minute = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._second = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcTime_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcTime
        this._category = categories.none
        this._id = 29
        this._size = 5
        this._checksum = 0
        this._hour = 0
        this._minute = 0
        this._second = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_hour(value) {
        this._hour = value
    }
    set_minute(value) {
        this._minute = value
    }
    set_second(value) {
        this._second = value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._hour)
        index += 1
        struct("<B").pack_into(buf, index, this._minute)
        index += 1
        struct("<B").pack_into(buf, index, this._second)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_hour() {
        return this._hour
    }
    get_minute() {
        return this._minute
    }
    get_second() {
        return this._second
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.hour, value: this.get_hour()})
        data.push({field: fields.minute, value: this.get_minute()})
        data.push({field: fields.second, value: this.get_second()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._hour = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._minute = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._second = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcTime_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcTime
        this._category = categories.none
        this._id = 30
        this._size = 5
        this._checksum = 0
        this._hour = 0
        this._minute = 0
        this._second = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_hour(value) {
        this._hour = value
    }
    set_minute(value) {
        this._minute = value
    }
    set_second(value) {
        this._second = value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._hour)
        index += 1
        struct("<B").pack_into(buf, index, this._minute)
        index += 1
        struct("<B").pack_into(buf, index, this._second)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_hour() {
        return this._hour
    }
    get_minute() {
        return this._minute
    }
    get_second() {
        return this._second
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.hour, value: this.get_hour()})
        data.push({field: fields.minute, value: this.get_minute()})
        data.push({field: fields.second, value: this.get_second()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._hour = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._minute = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._second = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class RtcTime_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.RtcTime
        this._category = categories.none
        this._id = 31
        this._size = 5
        this._checksum = 0
        this._hour = 0
        this._minute = 0
        this._second = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_hour(value) {
        this._hour = value
    }
    set_minute(value) {
        this._minute = value
    }
    set_second(value) {
        this._second = value
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._hour)
        index += 1
        struct("<B").pack_into(buf, index, this._minute)
        index += 1
        struct("<B").pack_into(buf, index, this._second)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_hour() {
        return this._hour
    }
    get_minute() {
        return this._minute
    }
    get_second() {
        return this._second
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.hour, value: this.get_hour()})
        data.push({field: fields.minute, value: this.get_minute()})
        data.push({field: fields.second, value: this.get_second()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._hour = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._minute = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._second = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_00_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_00
        this._category = categories.none
        this._id = 50
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_ambient_pressure_bar = 0
        this._edda_controller_can_rx_time_max_microsecond = 0
        this._edda_controller_board_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_ambient_pressure_bar(value) {
        this._edda_controller_ambient_pressure_bar = packedFloat_to_uint(value, 0, 1.5, 2)
    }
    set_edda_controller_can_rx_time_max_microsecond(value) {
        this._edda_controller_can_rx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_board_temperature_celsius(value) {
        this._edda_controller_board_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_ambient_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_can_rx_time_max_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_board_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_ambient_pressure_bar() {
        return uint_to_scaledFloat(this._edda_controller_ambient_pressure_bar, 0, 1.5, 2)
    }
    get_edda_controller_can_rx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_rx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_controller_board_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_controller_board_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_ambient_pressure_bar, value: this.get_edda_controller_ambient_pressure_bar()})
        data.push({field: fields.edda_controller_can_rx_time_max_microsecond, value: this.get_edda_controller_can_rx_time_max_microsecond()})
        data.push({field: fields.edda_controller_board_temperature_celsius, value: this.get_edda_controller_board_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_ambient_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_can_rx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_board_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_01_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_01
        this._category = categories.none
        this._id = 51
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_can_rx_time_microsecond = 0
        this._edda_controller_can_rx_time_min_microsecond = 0
        this._edda_controller_humidity_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_can_rx_time_microsecond(value) {
        this._edda_controller_can_rx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_can_rx_time_min_microsecond(value) {
        this._edda_controller_can_rx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_humidity_sensor_temperature_celsius(value) {
        this._edda_controller_humidity_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_can_rx_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_can_rx_time_min_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_humidity_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_can_rx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_rx_time_microsecond, 0, 10000, 2)
    }
    get_edda_controller_can_rx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_rx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_controller_humidity_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_controller_humidity_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_can_rx_time_microsecond, value: this.get_edda_controller_can_rx_time_microsecond()})
        data.push({field: fields.edda_controller_can_rx_time_min_microsecond, value: this.get_edda_controller_can_rx_time_min_microsecond()})
        data.push({field: fields.edda_controller_humidity_sensor_temperature_celsius, value: this.get_edda_controller_humidity_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_can_rx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_can_rx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_humidity_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_02_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_02
        this._category = categories.none
        this._id = 52
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_can_tx_time_max_microsecond = 0
        this._edda_controller_can_tx_time_microsecond = 0
        this._edda_controller_imu_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_can_tx_time_max_microsecond(value) {
        this._edda_controller_can_tx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_can_tx_time_microsecond(value) {
        this._edda_controller_can_tx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_imu_temperature_celsius(value) {
        this._edda_controller_imu_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_can_tx_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_can_tx_time_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_imu_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_can_tx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_tx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_controller_can_tx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_tx_time_microsecond, 0, 10000, 2)
    }
    get_edda_controller_imu_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_controller_imu_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_can_tx_time_max_microsecond, value: this.get_edda_controller_can_tx_time_max_microsecond()})
        data.push({field: fields.edda_controller_can_tx_time_microsecond, value: this.get_edda_controller_can_tx_time_microsecond()})
        data.push({field: fields.edda_controller_imu_temperature_celsius, value: this.get_edda_controller_imu_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_can_tx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_can_tx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_imu_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_03_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_03
        this._category = categories.none
        this._id = 53
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_can_tx_time_min_microsecond = 0
        this._edda_controller_input_current_ampere = 0
        this._edda_controller_internal_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_can_tx_time_min_microsecond(value) {
        this._edda_controller_can_tx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_controller_input_current_ampere(value) {
        this._edda_controller_input_current_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_controller_internal_temperature_celsius(value) {
        this._edda_controller_internal_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_can_tx_time_min_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_input_current_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_internal_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_can_tx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_can_tx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_controller_input_current_ampere() {
        return uint_to_scaledFloat(this._edda_controller_input_current_ampere, -15, 15, 2)
    }
    get_edda_controller_internal_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_controller_internal_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_can_tx_time_min_microsecond, value: this.get_edda_controller_can_tx_time_min_microsecond()})
        data.push({field: fields.edda_controller_input_current_ampere, value: this.get_edda_controller_input_current_ampere()})
        data.push({field: fields.edda_controller_internal_temperature_celsius, value: this.get_edda_controller_internal_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_can_tx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_input_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_internal_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_04_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_04
        this._category = categories.none
        this._id = 54
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_input_current_max_ampere = 0
        this._edda_controller_input_current_min_ampere = 0
        this._edda_controller_pressure_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_input_current_max_ampere(value) {
        this._edda_controller_input_current_max_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_controller_input_current_min_ampere(value) {
        this._edda_controller_input_current_min_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_controller_pressure_sensor_temperature_celsius(value) {
        this._edda_controller_pressure_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_input_current_max_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_input_current_min_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_pressure_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_input_current_max_ampere() {
        return uint_to_scaledFloat(this._edda_controller_input_current_max_ampere, -15, 15, 2)
    }
    get_edda_controller_input_current_min_ampere() {
        return uint_to_scaledFloat(this._edda_controller_input_current_min_ampere, -15, 15, 2)
    }
    get_edda_controller_pressure_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_controller_pressure_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_input_current_max_ampere, value: this.get_edda_controller_input_current_max_ampere()})
        data.push({field: fields.edda_controller_input_current_min_ampere, value: this.get_edda_controller_input_current_min_ampere()})
        data.push({field: fields.edda_controller_pressure_sensor_temperature_celsius, value: this.get_edda_controller_pressure_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_input_current_max_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_input_current_min_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_pressure_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_05_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_05
        this._category = categories.none
        this._id = 55
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_input_voltage_max_volt = 0
        this._edda_controller_input_voltage_min_volt = 0
        this._edda_controller_relative_humidity_percentage = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_input_voltage_max_volt(value) {
        this._edda_controller_input_voltage_max_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_controller_input_voltage_min_volt(value) {
        this._edda_controller_input_voltage_min_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_controller_relative_humidity_percentage(value) {
        this._edda_controller_relative_humidity_percentage = packedFloat_to_uint(value, 0, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_input_voltage_max_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_input_voltage_min_volt)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_controller_relative_humidity_percentage)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_input_voltage_max_volt() {
        return uint_to_scaledFloat(this._edda_controller_input_voltage_max_volt, 0, 36, 2)
    }
    get_edda_controller_input_voltage_min_volt() {
        return uint_to_scaledFloat(this._edda_controller_input_voltage_min_volt, 0, 36, 2)
    }
    get_edda_controller_relative_humidity_percentage() {
        return uint_to_scaledFloat(this._edda_controller_relative_humidity_percentage, 0, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_input_voltage_max_volt, value: this.get_edda_controller_input_voltage_max_volt()})
        data.push({field: fields.edda_controller_input_voltage_min_volt, value: this.get_edda_controller_input_voltage_min_volt()})
        data.push({field: fields.edda_controller_relative_humidity_percentage, value: this.get_edda_controller_relative_humidity_percentage()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_input_voltage_max_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_input_voltage_min_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_relative_humidity_percentage = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_06_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_06
        this._category = categories.none
        this._id = 56
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_input_voltage_volt = 0
        this._edda_controller_latency_edda_ground_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_input_voltage_volt(value) {
        this._edda_controller_input_voltage_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_controller_latency_edda_ground_time_max_millisecond(value) {
        this._edda_controller_latency_edda_ground_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_input_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_ground_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_input_voltage_volt() {
        return uint_to_scaledFloat(this._edda_controller_input_voltage_volt, 0, 36, 2)
    }
    get_edda_controller_latency_edda_ground_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_ground_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_input_voltage_volt, value: this.get_edda_controller_input_voltage_volt()})
        data.push({field: fields.edda_controller_latency_edda_ground_time_max_millisecond, value: this.get_edda_controller_latency_edda_ground_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_input_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_ground_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_07_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_07
        this._category = categories.none
        this._id = 57
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_ground_time_min_millisecond = 0
        this._edda_controller_latency_edda_temperature_1_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_ground_time_min_millisecond(value) {
        this._edda_controller_latency_edda_ground_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_latency_edda_temperature_1_time_max_millisecond(value) {
        this._edda_controller_latency_edda_temperature_1_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_ground_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_1_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_ground_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_ground_time_min_millisecond, 0, 500, 2)
    }
    get_edda_controller_latency_edda_temperature_1_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_1_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_ground_time_min_millisecond, value: this.get_edda_controller_latency_edda_ground_time_min_millisecond()})
        data.push({field: fields.edda_controller_latency_edda_temperature_1_time_max_millisecond, value: this.get_edda_controller_latency_edda_temperature_1_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_ground_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_temperature_1_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_08_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_08
        this._category = categories.none
        this._id = 58
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_temperature_1_time_min_millisecond = 0
        this._edda_controller_latency_edda_temperature_2_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_temperature_1_time_min_millisecond(value) {
        this._edda_controller_latency_edda_temperature_1_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_latency_edda_temperature_2_time_max_millisecond(value) {
        this._edda_controller_latency_edda_temperature_2_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_1_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_2_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_temperature_1_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_1_time_min_millisecond, 0, 500, 2)
    }
    get_edda_controller_latency_edda_temperature_2_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_2_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_temperature_1_time_min_millisecond, value: this.get_edda_controller_latency_edda_temperature_1_time_min_millisecond()})
        data.push({field: fields.edda_controller_latency_edda_temperature_2_time_max_millisecond, value: this.get_edda_controller_latency_edda_temperature_2_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_temperature_1_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_temperature_2_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_09_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_09
        this._category = categories.none
        this._id = 59
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_temperature_2_time_min_millisecond = 0
        this._edda_controller_latency_edda_transducer_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_temperature_2_time_min_millisecond(value) {
        this._edda_controller_latency_edda_temperature_2_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_latency_edda_transducer_time_max_millisecond(value) {
        this._edda_controller_latency_edda_transducer_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_2_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_transducer_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_temperature_2_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_2_time_min_millisecond, 0, 500, 2)
    }
    get_edda_controller_latency_edda_transducer_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_transducer_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_temperature_2_time_min_millisecond, value: this.get_edda_controller_latency_edda_temperature_2_time_min_millisecond()})
        data.push({field: fields.edda_controller_latency_edda_transducer_time_max_millisecond, value: this.get_edda_controller_latency_edda_transducer_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_temperature_2_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_transducer_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_10_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_10
        this._category = categories.none
        this._id = 60
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_transducer_time_min_millisecond = 0
        this._edda_controller_timing_time_freq_hertz = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_transducer_time_min_millisecond(value) {
        this._edda_controller_latency_edda_transducer_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_timing_time_freq_hertz(value) {
        this._edda_controller_timing_time_freq_hertz = packedFloat_to_uint(value, 0, 2000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_transducer_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_timing_time_freq_hertz)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_transducer_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_transducer_time_min_millisecond, 0, 500, 2)
    }
    get_edda_controller_timing_time_freq_hertz() {
        return uint_to_scaledFloat(this._edda_controller_timing_time_freq_hertz, 0, 2000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_transducer_time_min_millisecond, value: this.get_edda_controller_latency_edda_transducer_time_min_millisecond()})
        data.push({field: fields.edda_controller_timing_time_freq_hertz, value: this.get_edda_controller_timing_time_freq_hertz()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_transducer_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_timing_time_freq_hertz = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_11_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_11
        this._category = categories.none
        this._id = 61
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_timing_time_max_microsecond = 0
        this._edda_controller_timing_time_min_microsecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_timing_time_max_microsecond(value) {
        this._edda_controller_timing_time_max_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_controller_timing_time_min_microsecond(value) {
        this._edda_controller_timing_time_min_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_timing_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_timing_time_min_microsecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_timing_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_timing_time_max_microsecond, 0, 100000, 2)
    }
    get_edda_controller_timing_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_timing_time_min_microsecond, 0, 100000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_timing_time_max_microsecond, value: this.get_edda_controller_timing_time_max_microsecond()})
        data.push({field: fields.edda_controller_timing_time_min_microsecond, value: this.get_edda_controller_timing_time_min_microsecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_timing_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_timing_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_12_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_12
        this._category = categories.none
        this._id = 62
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_x_acceleration_max_gforce = 0
        this._edda_controller_x_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_x_acceleration_max_gforce(value) {
        this._edda_controller_x_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_controller_x_acceleration_min_gforce(value) {
        this._edda_controller_x_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_x_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_x_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_x_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_controller_x_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_controller_x_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_controller_x_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_x_acceleration_max_gforce, value: this.get_edda_controller_x_acceleration_max_gforce()})
        data.push({field: fields.edda_controller_x_acceleration_min_gforce, value: this.get_edda_controller_x_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_x_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_x_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_13_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_13
        this._category = categories.none
        this._id = 63
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_y_acceleration_max_gforce = 0
        this._edda_controller_y_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_y_acceleration_max_gforce(value) {
        this._edda_controller_y_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_controller_y_acceleration_min_gforce(value) {
        this._edda_controller_y_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_y_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_y_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_y_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_controller_y_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_controller_y_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_controller_y_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_y_acceleration_max_gforce, value: this.get_edda_controller_y_acceleration_max_gforce()})
        data.push({field: fields.edda_controller_y_acceleration_min_gforce, value: this.get_edda_controller_y_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_y_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_y_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_14_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_14
        this._category = categories.none
        this._id = 64
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_z_acceleration_max_gforce = 0
        this._edda_controller_z_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_z_acceleration_max_gforce(value) {
        this._edda_controller_z_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_controller_z_acceleration_min_gforce(value) {
        this._edda_controller_z_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_z_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_z_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_z_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_controller_z_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_controller_z_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_controller_z_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_z_acceleration_max_gforce, value: this.get_edda_controller_z_acceleration_max_gforce()})
        data.push({field: fields.edda_controller_z_acceleration_min_gforce, value: this.get_edda_controller_z_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_z_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_z_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_15_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_15
        this._category = categories.none
        this._id = 65
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_can_rx_size_rate_byte = 0
        this._edda_controller_can_tx_size_rate_byte = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_can_rx_size_rate_byte(value) {
        this._edda_controller_can_rx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    set_edda_controller_can_tx_size_rate_byte(value) {
        this._edda_controller_can_tx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_can_rx_size_rate_byte)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_can_tx_size_rate_byte)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_can_rx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_controller_can_rx_size_rate_byte, 0, 125000, 2)
    }
    get_edda_controller_can_tx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_controller_can_tx_size_rate_byte, 0, 125000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_can_rx_size_rate_byte, value: this.get_edda_controller_can_rx_size_rate_byte()})
        data.push({field: fields.edda_controller_can_tx_size_rate_byte, value: this.get_edda_controller_can_tx_size_rate_byte()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_can_rx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_can_tx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_16_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_16
        this._category = categories.none
        this._id = 66
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_ground_time_millisecond = 0
        this._edda_controller_latency_edda_temperature_1_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_ground_time_millisecond(value) {
        this._edda_controller_latency_edda_ground_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_latency_edda_temperature_1_time_millisecond(value) {
        this._edda_controller_latency_edda_temperature_1_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_ground_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_1_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_ground_time_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_ground_time_millisecond, 0, 500, 2)
    }
    get_edda_controller_latency_edda_temperature_1_time_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_1_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_ground_time_millisecond, value: this.get_edda_controller_latency_edda_ground_time_millisecond()})
        data.push({field: fields.edda_controller_latency_edda_temperature_1_time_millisecond, value: this.get_edda_controller_latency_edda_temperature_1_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_ground_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_temperature_1_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_17_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_17
        this._category = categories.none
        this._id = 67
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_latency_edda_temperature_2_time_millisecond = 0
        this._edda_controller_latency_edda_transducer_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_latency_edda_temperature_2_time_millisecond(value) {
        this._edda_controller_latency_edda_temperature_2_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_controller_latency_edda_transducer_time_millisecond(value) {
        this._edda_controller_latency_edda_transducer_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_temperature_2_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_latency_edda_transducer_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_latency_edda_temperature_2_time_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_temperature_2_time_millisecond, 0, 500, 2)
    }
    get_edda_controller_latency_edda_transducer_time_millisecond() {
        return uint_to_scaledFloat(this._edda_controller_latency_edda_transducer_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_latency_edda_temperature_2_time_millisecond, value: this.get_edda_controller_latency_edda_temperature_2_time_millisecond()})
        data.push({field: fields.edda_controller_latency_edda_transducer_time_millisecond, value: this.get_edda_controller_latency_edda_transducer_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_latency_edda_temperature_2_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_latency_edda_transducer_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_18_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_18
        this._category = categories.none
        this._id = 68
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_timing_time_microsecond = 0
        this._edda_controller_x_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_timing_time_microsecond(value) {
        this._edda_controller_timing_time_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_controller_x_acceleration_gforce(value) {
        this._edda_controller_x_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_timing_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_x_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_timing_time_microsecond() {
        return uint_to_scaledFloat(this._edda_controller_timing_time_microsecond, 0, 100000, 2)
    }
    get_edda_controller_x_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_controller_x_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_timing_time_microsecond, value: this.get_edda_controller_timing_time_microsecond()})
        data.push({field: fields.edda_controller_x_acceleration_gforce, value: this.get_edda_controller_x_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_timing_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_x_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_edda_controller_19_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_edda_controller_19
        this._category = categories.none
        this._id = 69
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_controller_y_acceleration_gforce = 0
        this._edda_controller_z_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_controller_y_acceleration_gforce(value) {
        this._edda_controller_y_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_controller_z_acceleration_gforce(value) {
        this._edda_controller_z_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_controller_y_acceleration_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_controller_z_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_controller_y_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_controller_y_acceleration_gforce, -20, 20, 2)
    }
    get_edda_controller_z_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_controller_z_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_controller_y_acceleration_gforce, value: this.get_edda_controller_y_acceleration_gforce()})
        data.push({field: fields.edda_controller_z_acceleration_gforce, value: this.get_edda_controller_z_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_controller_y_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_controller_z_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_00_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_00
        this._category = categories.none
        this._id = 152
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_bleed_valve_current_ampere = 0
        this._sindri_ignition_current_ampere = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_bleed_valve_current_ampere(value) {
        this._sindri_bleed_valve_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    set_sindri_ignition_current_ampere(value) {
        this._sindri_ignition_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_current_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_ignition_current_ampere)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_bleed_valve_current_ampere() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_current_ampere, 0, 30, 2)
    }
    get_sindri_ignition_current_ampere() {
        return uint_to_scaledFloat(this._sindri_ignition_current_ampere, 0, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_bleed_valve_current_ampere, value: this.get_sindri_bleed_valve_current_ampere()})
        data.push({field: fields.sindri_ignition_current_ampere, value: this.get_sindri_ignition_current_ampere()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_bleed_valve_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_ignition_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_01_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_01
        this._category = categories.none
        this._id = 153
        this._size = 5
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_main_valve_current_ampere = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_main_valve_current_ampere(value) {
        this._sindri_main_valve_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_main_valve_current_ampere)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_main_valve_current_ampere() {
        return uint_to_scaledFloat(this._sindri_main_valve_current_ampere, 0, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_main_valve_current_ampere, value: this.get_sindri_main_valve_current_ampere()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_main_valve_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_02_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_02
        this._category = categories.none
        this._id = 154
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_bleed_valve_estimation_current_ampere = 0
        this._sindri_bleed_valve_estimation_power_watt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_bleed_valve_estimation_current_ampere(value) {
        this._sindri_bleed_valve_estimation_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    set_sindri_bleed_valve_estimation_power_watt(value) {
        this._sindri_bleed_valve_estimation_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_estimation_current_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_estimation_power_watt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_bleed_valve_estimation_current_ampere() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_estimation_current_ampere, 0, 30, 2)
    }
    get_sindri_bleed_valve_estimation_power_watt() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_estimation_power_watt, 0, 1000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_bleed_valve_estimation_current_ampere, value: this.get_sindri_bleed_valve_estimation_current_ampere()})
        data.push({field: fields.sindri_bleed_valve_estimation_power_watt, value: this.get_sindri_bleed_valve_estimation_power_watt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_bleed_valve_estimation_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_bleed_valve_estimation_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_03_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_03
        this._category = categories.none
        this._id = 155
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_bleed_valve_estimation_resistance_ohm = 0
        this._sindri_bleed_valve_estimation_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_bleed_valve_estimation_resistance_ohm(value) {
        this._sindri_bleed_valve_estimation_resistance_ohm = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_bleed_valve_estimation_voltage_volt(value) {
        this._sindri_bleed_valve_estimation_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_estimation_resistance_ohm)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_estimation_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_bleed_valve_estimation_resistance_ohm() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_estimation_resistance_ohm, 0, 1000, 2)
    }
    get_sindri_bleed_valve_estimation_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_estimation_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_bleed_valve_estimation_resistance_ohm, value: this.get_sindri_bleed_valve_estimation_resistance_ohm()})
        data.push({field: fields.sindri_bleed_valve_estimation_voltage_volt, value: this.get_sindri_bleed_valve_estimation_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_bleed_valve_estimation_resistance_ohm = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_bleed_valve_estimation_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_04_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_04
        this._category = categories.none
        this._id = 156
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_bleed_valve_power_watt = 0
        this._sindri_bleed_valve_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_bleed_valve_power_watt(value) {
        this._sindri_bleed_valve_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_bleed_valve_voltage_volt(value) {
        this._sindri_bleed_valve_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_power_watt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_bleed_valve_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_bleed_valve_power_watt() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_power_watt, 0, 1000, 2)
    }
    get_sindri_bleed_valve_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_bleed_valve_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_bleed_valve_power_watt, value: this.get_sindri_bleed_valve_power_watt()})
        data.push({field: fields.sindri_bleed_valve_voltage_volt, value: this.get_sindri_bleed_valve_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_bleed_valve_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_bleed_valve_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_05_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_05
        this._category = categories.none
        this._id = 157
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_ignition_estimation_current_ampere = 0
        this._sindri_ignition_estimation_power_watt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_ignition_estimation_current_ampere(value) {
        this._sindri_ignition_estimation_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    set_sindri_ignition_estimation_power_watt(value) {
        this._sindri_ignition_estimation_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_ignition_estimation_current_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_ignition_estimation_power_watt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_ignition_estimation_current_ampere() {
        return uint_to_scaledFloat(this._sindri_ignition_estimation_current_ampere, 0, 30, 2)
    }
    get_sindri_ignition_estimation_power_watt() {
        return uint_to_scaledFloat(this._sindri_ignition_estimation_power_watt, 0, 1000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_ignition_estimation_current_ampere, value: this.get_sindri_ignition_estimation_current_ampere()})
        data.push({field: fields.sindri_ignition_estimation_power_watt, value: this.get_sindri_ignition_estimation_power_watt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_ignition_estimation_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_ignition_estimation_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_06_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_06
        this._category = categories.none
        this._id = 158
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_ignition_estimation_resistance_ohm = 0
        this._sindri_ignition_estimation_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_ignition_estimation_resistance_ohm(value) {
        this._sindri_ignition_estimation_resistance_ohm = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_ignition_estimation_voltage_volt(value) {
        this._sindri_ignition_estimation_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_ignition_estimation_resistance_ohm)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_ignition_estimation_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_ignition_estimation_resistance_ohm() {
        return uint_to_scaledFloat(this._sindri_ignition_estimation_resistance_ohm, 0, 1000, 2)
    }
    get_sindri_ignition_estimation_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_ignition_estimation_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_ignition_estimation_resistance_ohm, value: this.get_sindri_ignition_estimation_resistance_ohm()})
        data.push({field: fields.sindri_ignition_estimation_voltage_volt, value: this.get_sindri_ignition_estimation_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_ignition_estimation_resistance_ohm = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_ignition_estimation_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_07_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_07
        this._category = categories.none
        this._id = 159
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_ignition_power_watt = 0
        this._sindri_ignition_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_ignition_power_watt(value) {
        this._sindri_ignition_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_ignition_voltage_volt(value) {
        this._sindri_ignition_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_ignition_power_watt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_ignition_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_ignition_power_watt() {
        return uint_to_scaledFloat(this._sindri_ignition_power_watt, 0, 1000, 2)
    }
    get_sindri_ignition_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_ignition_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_ignition_power_watt, value: this.get_sindri_ignition_power_watt()})
        data.push({field: fields.sindri_ignition_voltage_volt, value: this.get_sindri_ignition_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_ignition_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_ignition_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_08_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_08
        this._category = categories.none
        this._id = 160
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_main_valve_estimation_current_ampere = 0
        this._sindri_main_valve_estimation_power_watt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_main_valve_estimation_current_ampere(value) {
        this._sindri_main_valve_estimation_current_ampere = packedFloat_to_uint(value, 0, 30, 2)
    }
    set_sindri_main_valve_estimation_power_watt(value) {
        this._sindri_main_valve_estimation_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_main_valve_estimation_current_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_main_valve_estimation_power_watt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_main_valve_estimation_current_ampere() {
        return uint_to_scaledFloat(this._sindri_main_valve_estimation_current_ampere, 0, 30, 2)
    }
    get_sindri_main_valve_estimation_power_watt() {
        return uint_to_scaledFloat(this._sindri_main_valve_estimation_power_watt, 0, 1000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_main_valve_estimation_current_ampere, value: this.get_sindri_main_valve_estimation_current_ampere()})
        data.push({field: fields.sindri_main_valve_estimation_power_watt, value: this.get_sindri_main_valve_estimation_power_watt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_main_valve_estimation_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_main_valve_estimation_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_09_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_09
        this._category = categories.none
        this._id = 161
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_main_valve_estimation_resistance_ohm = 0
        this._sindri_main_valve_estimation_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_main_valve_estimation_resistance_ohm(value) {
        this._sindri_main_valve_estimation_resistance_ohm = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_main_valve_estimation_voltage_volt(value) {
        this._sindri_main_valve_estimation_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_main_valve_estimation_resistance_ohm)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_main_valve_estimation_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_main_valve_estimation_resistance_ohm() {
        return uint_to_scaledFloat(this._sindri_main_valve_estimation_resistance_ohm, 0, 1000, 2)
    }
    get_sindri_main_valve_estimation_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_main_valve_estimation_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_main_valve_estimation_resistance_ohm, value: this.get_sindri_main_valve_estimation_resistance_ohm()})
        data.push({field: fields.sindri_main_valve_estimation_voltage_volt, value: this.get_sindri_main_valve_estimation_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_main_valve_estimation_resistance_ohm = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_main_valve_estimation_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_10_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_10
        this._category = categories.none
        this._id = 162
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_main_valve_power_watt = 0
        this._sindri_main_valve_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_main_valve_power_watt(value) {
        this._sindri_main_valve_power_watt = packedFloat_to_uint(value, 0, 1000, 2)
    }
    set_sindri_main_valve_voltage_volt(value) {
        this._sindri_main_valve_voltage_volt = packedFloat_to_uint(value, -30, 30, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_main_valve_power_watt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_main_valve_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_main_valve_power_watt() {
        return uint_to_scaledFloat(this._sindri_main_valve_power_watt, 0, 1000, 2)
    }
    get_sindri_main_valve_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_main_valve_voltage_volt, -30, 30, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_main_valve_power_watt, value: this.get_sindri_main_valve_power_watt()})
        data.push({field: fields.sindri_main_valve_voltage_volt, value: this.get_sindri_main_valve_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_main_valve_power_watt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_main_valve_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_11_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_11
        this._category = categories.none
        this._id = 163
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_oxidizer_tank_weight_max_kilogram = 0
        this._sindri_oxidizer_tank_weight_min_kilogram = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_oxidizer_tank_weight_max_kilogram(value) {
        this._sindri_oxidizer_tank_weight_max_kilogram = packedFloat_to_uint(value, 0, 100, 2)
    }
    set_sindri_oxidizer_tank_weight_min_kilogram(value) {
        this._sindri_oxidizer_tank_weight_min_kilogram = packedFloat_to_uint(value, 0, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_oxidizer_tank_weight_max_kilogram)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_oxidizer_tank_weight_min_kilogram)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_oxidizer_tank_weight_max_kilogram() {
        return uint_to_scaledFloat(this._sindri_oxidizer_tank_weight_max_kilogram, 0, 100, 2)
    }
    get_sindri_oxidizer_tank_weight_min_kilogram() {
        return uint_to_scaledFloat(this._sindri_oxidizer_tank_weight_min_kilogram, 0, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_oxidizer_tank_weight_max_kilogram, value: this.get_sindri_oxidizer_tank_weight_max_kilogram()})
        data.push({field: fields.sindri_oxidizer_tank_weight_min_kilogram, value: this.get_sindri_oxidizer_tank_weight_min_kilogram()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_oxidizer_tank_weight_max_kilogram = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_oxidizer_tank_weight_min_kilogram = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__ControllerBoard_sindri_12_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__ControllerBoard_sindri_12
        this._category = categories.none
        this._id = 164
        this._size = 5
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_oxidizer_tank_weight_kilogram = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_oxidizer_tank_weight_kilogram(value) {
        this._sindri_oxidizer_tank_weight_kilogram = packedFloat_to_uint(value, 0, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_oxidizer_tank_weight_kilogram)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_oxidizer_tank_weight_kilogram() {
        return uint_to_scaledFloat(this._sindri_oxidizer_tank_weight_kilogram, 0, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_oxidizer_tank_weight_kilogram, value: this.get_sindri_oxidizer_tank_weight_kilogram()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_oxidizer_tank_weight_kilogram = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_00_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_00
        this._category = categories.none
        this._id = 70
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_ambient_pressure_bar = 0
        this._edda_ground_can_rx_time_max_microsecond = 0
        this._edda_ground_board_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_ambient_pressure_bar(value) {
        this._edda_ground_ambient_pressure_bar = packedFloat_to_uint(value, 0, 1.5, 2)
    }
    set_edda_ground_can_rx_time_max_microsecond(value) {
        this._edda_ground_can_rx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_board_temperature_celsius(value) {
        this._edda_ground_board_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_ambient_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_can_rx_time_max_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_board_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_ambient_pressure_bar() {
        return uint_to_scaledFloat(this._edda_ground_ambient_pressure_bar, 0, 1.5, 2)
    }
    get_edda_ground_can_rx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_rx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_ground_board_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_ground_board_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_ambient_pressure_bar, value: this.get_edda_ground_ambient_pressure_bar()})
        data.push({field: fields.edda_ground_can_rx_time_max_microsecond, value: this.get_edda_ground_can_rx_time_max_microsecond()})
        data.push({field: fields.edda_ground_board_temperature_celsius, value: this.get_edda_ground_board_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_ambient_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_can_rx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_board_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_01_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_01
        this._category = categories.none
        this._id = 71
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_can_rx_time_microsecond = 0
        this._edda_ground_can_rx_time_min_microsecond = 0
        this._edda_ground_humidity_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_can_rx_time_microsecond(value) {
        this._edda_ground_can_rx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_can_rx_time_min_microsecond(value) {
        this._edda_ground_can_rx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_humidity_sensor_temperature_celsius(value) {
        this._edda_ground_humidity_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_can_rx_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_can_rx_time_min_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_humidity_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_can_rx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_rx_time_microsecond, 0, 10000, 2)
    }
    get_edda_ground_can_rx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_rx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_ground_humidity_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_ground_humidity_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_can_rx_time_microsecond, value: this.get_edda_ground_can_rx_time_microsecond()})
        data.push({field: fields.edda_ground_can_rx_time_min_microsecond, value: this.get_edda_ground_can_rx_time_min_microsecond()})
        data.push({field: fields.edda_ground_humidity_sensor_temperature_celsius, value: this.get_edda_ground_humidity_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_can_rx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_can_rx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_humidity_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_02_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_02
        this._category = categories.none
        this._id = 72
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_can_tx_time_max_microsecond = 0
        this._edda_ground_can_tx_time_microsecond = 0
        this._edda_ground_imu_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_can_tx_time_max_microsecond(value) {
        this._edda_ground_can_tx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_can_tx_time_microsecond(value) {
        this._edda_ground_can_tx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_imu_temperature_celsius(value) {
        this._edda_ground_imu_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_can_tx_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_can_tx_time_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_imu_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_can_tx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_tx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_ground_can_tx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_tx_time_microsecond, 0, 10000, 2)
    }
    get_edda_ground_imu_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_ground_imu_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_can_tx_time_max_microsecond, value: this.get_edda_ground_can_tx_time_max_microsecond()})
        data.push({field: fields.edda_ground_can_tx_time_microsecond, value: this.get_edda_ground_can_tx_time_microsecond()})
        data.push({field: fields.edda_ground_imu_temperature_celsius, value: this.get_edda_ground_imu_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_can_tx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_can_tx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_imu_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_03_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_03
        this._category = categories.none
        this._id = 73
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_can_tx_time_min_microsecond = 0
        this._edda_ground_input_current_ampere = 0
        this._edda_ground_internal_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_can_tx_time_min_microsecond(value) {
        this._edda_ground_can_tx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_ground_input_current_ampere(value) {
        this._edda_ground_input_current_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_ground_internal_temperature_celsius(value) {
        this._edda_ground_internal_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_can_tx_time_min_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_input_current_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_internal_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_can_tx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_can_tx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_ground_input_current_ampere() {
        return uint_to_scaledFloat(this._edda_ground_input_current_ampere, -15, 15, 2)
    }
    get_edda_ground_internal_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_ground_internal_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_can_tx_time_min_microsecond, value: this.get_edda_ground_can_tx_time_min_microsecond()})
        data.push({field: fields.edda_ground_input_current_ampere, value: this.get_edda_ground_input_current_ampere()})
        data.push({field: fields.edda_ground_internal_temperature_celsius, value: this.get_edda_ground_internal_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_can_tx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_input_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_internal_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_04_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_04
        this._category = categories.none
        this._id = 74
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_input_current_max_ampere = 0
        this._edda_ground_input_current_min_ampere = 0
        this._edda_ground_pressure_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_input_current_max_ampere(value) {
        this._edda_ground_input_current_max_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_ground_input_current_min_ampere(value) {
        this._edda_ground_input_current_min_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_ground_pressure_sensor_temperature_celsius(value) {
        this._edda_ground_pressure_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_input_current_max_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_input_current_min_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_pressure_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_input_current_max_ampere() {
        return uint_to_scaledFloat(this._edda_ground_input_current_max_ampere, -15, 15, 2)
    }
    get_edda_ground_input_current_min_ampere() {
        return uint_to_scaledFloat(this._edda_ground_input_current_min_ampere, -15, 15, 2)
    }
    get_edda_ground_pressure_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_ground_pressure_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_input_current_max_ampere, value: this.get_edda_ground_input_current_max_ampere()})
        data.push({field: fields.edda_ground_input_current_min_ampere, value: this.get_edda_ground_input_current_min_ampere()})
        data.push({field: fields.edda_ground_pressure_sensor_temperature_celsius, value: this.get_edda_ground_pressure_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_input_current_max_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_input_current_min_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_pressure_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_05_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_05
        this._category = categories.none
        this._id = 75
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_input_voltage_max_volt = 0
        this._edda_ground_input_voltage_min_volt = 0
        this._edda_ground_relative_humidity_percentage = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_input_voltage_max_volt(value) {
        this._edda_ground_input_voltage_max_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_ground_input_voltage_min_volt(value) {
        this._edda_ground_input_voltage_min_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_ground_relative_humidity_percentage(value) {
        this._edda_ground_relative_humidity_percentage = packedFloat_to_uint(value, 0, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_input_voltage_max_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_input_voltage_min_volt)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_ground_relative_humidity_percentage)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_input_voltage_max_volt() {
        return uint_to_scaledFloat(this._edda_ground_input_voltage_max_volt, 0, 36, 2)
    }
    get_edda_ground_input_voltage_min_volt() {
        return uint_to_scaledFloat(this._edda_ground_input_voltage_min_volt, 0, 36, 2)
    }
    get_edda_ground_relative_humidity_percentage() {
        return uint_to_scaledFloat(this._edda_ground_relative_humidity_percentage, 0, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_input_voltage_max_volt, value: this.get_edda_ground_input_voltage_max_volt()})
        data.push({field: fields.edda_ground_input_voltage_min_volt, value: this.get_edda_ground_input_voltage_min_volt()})
        data.push({field: fields.edda_ground_relative_humidity_percentage, value: this.get_edda_ground_relative_humidity_percentage()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_input_voltage_max_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_input_voltage_min_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_relative_humidity_percentage = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__GroundController_edda_ground_06_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_06
        this._category = categories.none
        this._id = 76
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_input_voltage_volt = 0
        this._edda_ground_latency_edda_controller_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_input_voltage_volt(value) {
        this._edda_ground_input_voltage_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_ground_latency_edda_controller_time_max_millisecond(value) {
        this._edda_ground_latency_edda_controller_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_input_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_controller_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_input_voltage_volt() {
        return uint_to_scaledFloat(this._edda_ground_input_voltage_volt, 0, 36, 2)
    }
    get_edda_ground_latency_edda_controller_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_controller_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_input_voltage_volt, value: this.get_edda_ground_input_voltage_volt()})
        data.push({field: fields.edda_ground_latency_edda_controller_time_max_millisecond, value: this.get_edda_ground_latency_edda_controller_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_input_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_controller_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_07_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_07
        this._category = categories.none
        this._id = 77
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_controller_time_min_millisecond = 0
        this._edda_ground_latency_edda_temperature_1_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_controller_time_min_millisecond(value) {
        this._edda_ground_latency_edda_controller_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_latency_edda_temperature_1_time_max_millisecond(value) {
        this._edda_ground_latency_edda_temperature_1_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_controller_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_1_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_controller_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_controller_time_min_millisecond, 0, 500, 2)
    }
    get_edda_ground_latency_edda_temperature_1_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_1_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_controller_time_min_millisecond, value: this.get_edda_ground_latency_edda_controller_time_min_millisecond()})
        data.push({field: fields.edda_ground_latency_edda_temperature_1_time_max_millisecond, value: this.get_edda_ground_latency_edda_temperature_1_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_controller_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_temperature_1_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_08_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_08
        this._category = categories.none
        this._id = 78
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_temperature_1_time_min_millisecond = 0
        this._edda_ground_latency_edda_temperature_2_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_temperature_1_time_min_millisecond(value) {
        this._edda_ground_latency_edda_temperature_1_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_latency_edda_temperature_2_time_max_millisecond(value) {
        this._edda_ground_latency_edda_temperature_2_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_1_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_2_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_temperature_1_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_1_time_min_millisecond, 0, 500, 2)
    }
    get_edda_ground_latency_edda_temperature_2_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_2_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_temperature_1_time_min_millisecond, value: this.get_edda_ground_latency_edda_temperature_1_time_min_millisecond()})
        data.push({field: fields.edda_ground_latency_edda_temperature_2_time_max_millisecond, value: this.get_edda_ground_latency_edda_temperature_2_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_temperature_1_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_temperature_2_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_09_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_09
        this._category = categories.none
        this._id = 79
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_temperature_2_time_min_millisecond = 0
        this._edda_ground_latency_edda_transducer_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_temperature_2_time_min_millisecond(value) {
        this._edda_ground_latency_edda_temperature_2_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_latency_edda_transducer_time_max_millisecond(value) {
        this._edda_ground_latency_edda_transducer_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_2_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_transducer_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_temperature_2_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_2_time_min_millisecond, 0, 500, 2)
    }
    get_edda_ground_latency_edda_transducer_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_transducer_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_temperature_2_time_min_millisecond, value: this.get_edda_ground_latency_edda_temperature_2_time_min_millisecond()})
        data.push({field: fields.edda_ground_latency_edda_transducer_time_max_millisecond, value: this.get_edda_ground_latency_edda_transducer_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_temperature_2_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_transducer_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_10_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_10
        this._category = categories.none
        this._id = 80
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_transducer_time_min_millisecond = 0
        this._edda_ground_timing_time_freq_hertz = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_transducer_time_min_millisecond(value) {
        this._edda_ground_latency_edda_transducer_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_timing_time_freq_hertz(value) {
        this._edda_ground_timing_time_freq_hertz = packedFloat_to_uint(value, 0, 2000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_transducer_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_timing_time_freq_hertz)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_transducer_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_transducer_time_min_millisecond, 0, 500, 2)
    }
    get_edda_ground_timing_time_freq_hertz() {
        return uint_to_scaledFloat(this._edda_ground_timing_time_freq_hertz, 0, 2000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_transducer_time_min_millisecond, value: this.get_edda_ground_latency_edda_transducer_time_min_millisecond()})
        data.push({field: fields.edda_ground_timing_time_freq_hertz, value: this.get_edda_ground_timing_time_freq_hertz()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_transducer_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_timing_time_freq_hertz = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_11_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_11
        this._category = categories.none
        this._id = 81
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_timing_time_max_microsecond = 0
        this._edda_ground_timing_time_min_microsecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_timing_time_max_microsecond(value) {
        this._edda_ground_timing_time_max_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_ground_timing_time_min_microsecond(value) {
        this._edda_ground_timing_time_min_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_timing_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_timing_time_min_microsecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_timing_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_timing_time_max_microsecond, 0, 100000, 2)
    }
    get_edda_ground_timing_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_timing_time_min_microsecond, 0, 100000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_timing_time_max_microsecond, value: this.get_edda_ground_timing_time_max_microsecond()})
        data.push({field: fields.edda_ground_timing_time_min_microsecond, value: this.get_edda_ground_timing_time_min_microsecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_timing_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_timing_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_12_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_12
        this._category = categories.none
        this._id = 82
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_x_acceleration_max_gforce = 0
        this._edda_ground_x_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_x_acceleration_max_gforce(value) {
        this._edda_ground_x_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_ground_x_acceleration_min_gforce(value) {
        this._edda_ground_x_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_x_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_x_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_x_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_ground_x_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_ground_x_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_ground_x_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_x_acceleration_max_gforce, value: this.get_edda_ground_x_acceleration_max_gforce()})
        data.push({field: fields.edda_ground_x_acceleration_min_gforce, value: this.get_edda_ground_x_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_x_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_x_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_13_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_13
        this._category = categories.none
        this._id = 83
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_y_acceleration_max_gforce = 0
        this._edda_ground_y_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_y_acceleration_max_gforce(value) {
        this._edda_ground_y_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_ground_y_acceleration_min_gforce(value) {
        this._edda_ground_y_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_y_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_y_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_y_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_ground_y_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_ground_y_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_ground_y_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_y_acceleration_max_gforce, value: this.get_edda_ground_y_acceleration_max_gforce()})
        data.push({field: fields.edda_ground_y_acceleration_min_gforce, value: this.get_edda_ground_y_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_y_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_y_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_14_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_14
        this._category = categories.none
        this._id = 84
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_z_acceleration_max_gforce = 0
        this._edda_ground_z_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_z_acceleration_max_gforce(value) {
        this._edda_ground_z_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_ground_z_acceleration_min_gforce(value) {
        this._edda_ground_z_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_z_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_z_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_z_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_ground_z_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_ground_z_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_ground_z_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_z_acceleration_max_gforce, value: this.get_edda_ground_z_acceleration_max_gforce()})
        data.push({field: fields.edda_ground_z_acceleration_min_gforce, value: this.get_edda_ground_z_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_z_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_z_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_15_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_15
        this._category = categories.none
        this._id = 85
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_can_rx_size_rate_byte = 0
        this._edda_ground_can_tx_size_rate_byte = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_can_rx_size_rate_byte(value) {
        this._edda_ground_can_rx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    set_edda_ground_can_tx_size_rate_byte(value) {
        this._edda_ground_can_tx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_can_rx_size_rate_byte)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_can_tx_size_rate_byte)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_can_rx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_ground_can_rx_size_rate_byte, 0, 125000, 2)
    }
    get_edda_ground_can_tx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_ground_can_tx_size_rate_byte, 0, 125000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_can_rx_size_rate_byte, value: this.get_edda_ground_can_rx_size_rate_byte()})
        data.push({field: fields.edda_ground_can_tx_size_rate_byte, value: this.get_edda_ground_can_tx_size_rate_byte()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_can_rx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_can_tx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_16_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_16
        this._category = categories.none
        this._id = 86
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_controller_time_millisecond = 0
        this._edda_ground_latency_edda_temperature_1_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_controller_time_millisecond(value) {
        this._edda_ground_latency_edda_controller_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_latency_edda_temperature_1_time_millisecond(value) {
        this._edda_ground_latency_edda_temperature_1_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_controller_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_1_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_controller_time_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_controller_time_millisecond, 0, 500, 2)
    }
    get_edda_ground_latency_edda_temperature_1_time_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_1_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_controller_time_millisecond, value: this.get_edda_ground_latency_edda_controller_time_millisecond()})
        data.push({field: fields.edda_ground_latency_edda_temperature_1_time_millisecond, value: this.get_edda_ground_latency_edda_temperature_1_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_controller_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_temperature_1_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_17_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_17
        this._category = categories.none
        this._id = 87
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_latency_edda_temperature_2_time_millisecond = 0
        this._edda_ground_latency_edda_transducer_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_latency_edda_temperature_2_time_millisecond(value) {
        this._edda_ground_latency_edda_temperature_2_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_ground_latency_edda_transducer_time_millisecond(value) {
        this._edda_ground_latency_edda_transducer_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_temperature_2_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_latency_edda_transducer_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_latency_edda_temperature_2_time_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_temperature_2_time_millisecond, 0, 500, 2)
    }
    get_edda_ground_latency_edda_transducer_time_millisecond() {
        return uint_to_scaledFloat(this._edda_ground_latency_edda_transducer_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_latency_edda_temperature_2_time_millisecond, value: this.get_edda_ground_latency_edda_temperature_2_time_millisecond()})
        data.push({field: fields.edda_ground_latency_edda_transducer_time_millisecond, value: this.get_edda_ground_latency_edda_transducer_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_latency_edda_temperature_2_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_latency_edda_transducer_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_18_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_18
        this._category = categories.none
        this._id = 88
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_timing_time_microsecond = 0
        this._edda_ground_x_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_timing_time_microsecond(value) {
        this._edda_ground_timing_time_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_ground_x_acceleration_gforce(value) {
        this._edda_ground_x_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_timing_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_x_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_timing_time_microsecond() {
        return uint_to_scaledFloat(this._edda_ground_timing_time_microsecond, 0, 100000, 2)
    }
    get_edda_ground_x_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_ground_x_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_timing_time_microsecond, value: this.get_edda_ground_timing_time_microsecond()})
        data.push({field: fields.edda_ground_x_acceleration_gforce, value: this.get_edda_ground_x_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_timing_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_x_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__GroundController_edda_ground_19_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__GroundController_edda_ground_19
        this._category = categories.none
        this._id = 89
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_ground_y_acceleration_gforce = 0
        this._edda_ground_z_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_ground_y_acceleration_gforce(value) {
        this._edda_ground_y_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_ground_z_acceleration_gforce(value) {
        this._edda_ground_z_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_ground_y_acceleration_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_ground_z_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_ground_y_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_ground_y_acceleration_gforce, -20, 20, 2)
    }
    get_edda_ground_z_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_ground_z_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_ground_y_acceleration_gforce, value: this.get_edda_ground_y_acceleration_gforce()})
        data.push({field: fields.edda_ground_z_acceleration_gforce, value: this.get_edda_ground_z_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_ground_y_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_ground_z_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_00_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_00
        this._category = categories.none
        this._id = 90
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_ambient_pressure_bar = 0
        this._edda_temperature_1_can_rx_time_max_microsecond = 0
        this._edda_temperature_1_board_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_ambient_pressure_bar(value) {
        this._edda_temperature_1_ambient_pressure_bar = packedFloat_to_uint(value, 0, 1.5, 2)
    }
    set_edda_temperature_1_can_rx_time_max_microsecond(value) {
        this._edda_temperature_1_can_rx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_board_temperature_celsius(value) {
        this._edda_temperature_1_board_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_ambient_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_rx_time_max_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_board_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_ambient_pressure_bar() {
        return uint_to_scaledFloat(this._edda_temperature_1_ambient_pressure_bar, 0, 1.5, 2)
    }
    get_edda_temperature_1_can_rx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_rx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_board_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_board_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_ambient_pressure_bar, value: this.get_edda_temperature_1_ambient_pressure_bar()})
        data.push({field: fields.edda_temperature_1_can_rx_time_max_microsecond, value: this.get_edda_temperature_1_can_rx_time_max_microsecond()})
        data.push({field: fields.edda_temperature_1_board_temperature_celsius, value: this.get_edda_temperature_1_board_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_ambient_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_can_rx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_board_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_01_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_01
        this._category = categories.none
        this._id = 91
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_can_rx_time_microsecond = 0
        this._edda_temperature_1_can_rx_time_min_microsecond = 0
        this._edda_temperature_1_humidity_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_can_rx_time_microsecond(value) {
        this._edda_temperature_1_can_rx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_can_rx_time_min_microsecond(value) {
        this._edda_temperature_1_can_rx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_humidity_sensor_temperature_celsius(value) {
        this._edda_temperature_1_humidity_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_rx_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_rx_time_min_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_humidity_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_can_rx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_rx_time_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_can_rx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_rx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_humidity_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_humidity_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_can_rx_time_microsecond, value: this.get_edda_temperature_1_can_rx_time_microsecond()})
        data.push({field: fields.edda_temperature_1_can_rx_time_min_microsecond, value: this.get_edda_temperature_1_can_rx_time_min_microsecond()})
        data.push({field: fields.edda_temperature_1_humidity_sensor_temperature_celsius, value: this.get_edda_temperature_1_humidity_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_can_rx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_can_rx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_humidity_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_02_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_02
        this._category = categories.none
        this._id = 92
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_can_tx_time_max_microsecond = 0
        this._edda_temperature_1_can_tx_time_microsecond = 0
        this._edda_temperature_1_imu_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_can_tx_time_max_microsecond(value) {
        this._edda_temperature_1_can_tx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_can_tx_time_microsecond(value) {
        this._edda_temperature_1_can_tx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_imu_temperature_celsius(value) {
        this._edda_temperature_1_imu_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_tx_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_tx_time_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_imu_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_can_tx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_tx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_can_tx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_tx_time_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_imu_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_imu_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_can_tx_time_max_microsecond, value: this.get_edda_temperature_1_can_tx_time_max_microsecond()})
        data.push({field: fields.edda_temperature_1_can_tx_time_microsecond, value: this.get_edda_temperature_1_can_tx_time_microsecond()})
        data.push({field: fields.edda_temperature_1_imu_temperature_celsius, value: this.get_edda_temperature_1_imu_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_can_tx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_can_tx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_imu_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_03_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_03
        this._category = categories.none
        this._id = 93
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_can_tx_time_min_microsecond = 0
        this._edda_temperature_1_input_current_ampere = 0
        this._edda_temperature_1_internal_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_can_tx_time_min_microsecond(value) {
        this._edda_temperature_1_can_tx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_1_input_current_ampere(value) {
        this._edda_temperature_1_input_current_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_1_internal_temperature_celsius(value) {
        this._edda_temperature_1_internal_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_tx_time_min_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_current_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_internal_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_can_tx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_tx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_1_input_current_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_current_ampere, -15, 15, 2)
    }
    get_edda_temperature_1_internal_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_internal_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_can_tx_time_min_microsecond, value: this.get_edda_temperature_1_can_tx_time_min_microsecond()})
        data.push({field: fields.edda_temperature_1_input_current_ampere, value: this.get_edda_temperature_1_input_current_ampere()})
        data.push({field: fields.edda_temperature_1_internal_temperature_celsius, value: this.get_edda_temperature_1_internal_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_can_tx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_input_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_internal_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_04_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_04
        this._category = categories.none
        this._id = 94
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_input_current_max_ampere = 0
        this._edda_temperature_1_input_current_min_ampere = 0
        this._edda_temperature_1_pressure_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_input_current_max_ampere(value) {
        this._edda_temperature_1_input_current_max_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_1_input_current_min_ampere(value) {
        this._edda_temperature_1_input_current_min_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_1_pressure_sensor_temperature_celsius(value) {
        this._edda_temperature_1_pressure_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_current_max_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_current_min_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_pressure_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_input_current_max_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_current_max_ampere, -15, 15, 2)
    }
    get_edda_temperature_1_input_current_min_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_current_min_ampere, -15, 15, 2)
    }
    get_edda_temperature_1_pressure_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_pressure_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_input_current_max_ampere, value: this.get_edda_temperature_1_input_current_max_ampere()})
        data.push({field: fields.edda_temperature_1_input_current_min_ampere, value: this.get_edda_temperature_1_input_current_min_ampere()})
        data.push({field: fields.edda_temperature_1_pressure_sensor_temperature_celsius, value: this.get_edda_temperature_1_pressure_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_input_current_max_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_input_current_min_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_pressure_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_05_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_05
        this._category = categories.none
        this._id = 95
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_input_voltage_max_volt = 0
        this._edda_temperature_1_input_voltage_min_volt = 0
        this._edda_temperature_1_relative_humidity_percentage = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_input_voltage_max_volt(value) {
        this._edda_temperature_1_input_voltage_max_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_1_input_voltage_min_volt(value) {
        this._edda_temperature_1_input_voltage_min_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_1_relative_humidity_percentage(value) {
        this._edda_temperature_1_relative_humidity_percentage = packedFloat_to_uint(value, 0, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_voltage_max_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_voltage_min_volt)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_1_relative_humidity_percentage)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_input_voltage_max_volt() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_voltage_max_volt, 0, 36, 2)
    }
    get_edda_temperature_1_input_voltage_min_volt() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_voltage_min_volt, 0, 36, 2)
    }
    get_edda_temperature_1_relative_humidity_percentage() {
        return uint_to_scaledFloat(this._edda_temperature_1_relative_humidity_percentage, 0, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_input_voltage_max_volt, value: this.get_edda_temperature_1_input_voltage_max_volt()})
        data.push({field: fields.edda_temperature_1_input_voltage_min_volt, value: this.get_edda_temperature_1_input_voltage_min_volt()})
        data.push({field: fields.edda_temperature_1_relative_humidity_percentage, value: this.get_edda_temperature_1_relative_humidity_percentage()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_input_voltage_max_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_input_voltage_min_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_relative_humidity_percentage = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_06_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_06
        this._category = categories.none
        this._id = 96
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_input_voltage_volt = 0
        this._edda_temperature_1_latency_edda_controller_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_input_voltage_volt(value) {
        this._edda_temperature_1_input_voltage_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_1_latency_edda_controller_time_max_millisecond(value) {
        this._edda_temperature_1_latency_edda_controller_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_input_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_controller_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_input_voltage_volt() {
        return uint_to_scaledFloat(this._edda_temperature_1_input_voltage_volt, 0, 36, 2)
    }
    get_edda_temperature_1_latency_edda_controller_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_controller_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_input_voltage_volt, value: this.get_edda_temperature_1_input_voltage_volt()})
        data.push({field: fields.edda_temperature_1_latency_edda_controller_time_max_millisecond, value: this.get_edda_temperature_1_latency_edda_controller_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_input_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_controller_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_07_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_07
        this._category = categories.none
        this._id = 97
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_controller_time_min_millisecond = 0
        this._edda_temperature_1_latency_edda_ground_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_controller_time_min_millisecond(value) {
        this._edda_temperature_1_latency_edda_controller_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_latency_edda_ground_time_max_millisecond(value) {
        this._edda_temperature_1_latency_edda_ground_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_controller_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_ground_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_controller_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_controller_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_latency_edda_ground_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_ground_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_controller_time_min_millisecond, value: this.get_edda_temperature_1_latency_edda_controller_time_min_millisecond()})
        data.push({field: fields.edda_temperature_1_latency_edda_ground_time_max_millisecond, value: this.get_edda_temperature_1_latency_edda_ground_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_controller_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_ground_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_08_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_08
        this._category = categories.none
        this._id = 98
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_ground_time_min_millisecond = 0
        this._edda_temperature_1_latency_edda_temperature_2_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_ground_time_min_millisecond(value) {
        this._edda_temperature_1_latency_edda_ground_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_latency_edda_temperature_2_time_max_millisecond(value) {
        this._edda_temperature_1_latency_edda_temperature_2_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_ground_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_temperature_2_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_ground_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_ground_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_latency_edda_temperature_2_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_temperature_2_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_ground_time_min_millisecond, value: this.get_edda_temperature_1_latency_edda_ground_time_min_millisecond()})
        data.push({field: fields.edda_temperature_1_latency_edda_temperature_2_time_max_millisecond, value: this.get_edda_temperature_1_latency_edda_temperature_2_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_ground_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_temperature_2_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_09_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_09
        this._category = categories.none
        this._id = 99
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_temperature_2_time_min_millisecond = 0
        this._edda_temperature_1_latency_edda_transducer_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_temperature_2_time_min_millisecond(value) {
        this._edda_temperature_1_latency_edda_temperature_2_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_latency_edda_transducer_time_max_millisecond(value) {
        this._edda_temperature_1_latency_edda_transducer_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_temperature_2_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_transducer_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_temperature_2_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_temperature_2_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_latency_edda_transducer_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_transducer_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_temperature_2_time_min_millisecond, value: this.get_edda_temperature_1_latency_edda_temperature_2_time_min_millisecond()})
        data.push({field: fields.edda_temperature_1_latency_edda_transducer_time_max_millisecond, value: this.get_edda_temperature_1_latency_edda_transducer_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_temperature_2_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_transducer_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_10_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_10
        this._category = categories.none
        this._id = 100
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_transducer_time_min_millisecond = 0
        this._edda_temperature_1_timing_time_freq_hertz = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_transducer_time_min_millisecond(value) {
        this._edda_temperature_1_latency_edda_transducer_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_timing_time_freq_hertz(value) {
        this._edda_temperature_1_timing_time_freq_hertz = packedFloat_to_uint(value, 0, 2000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_transducer_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_timing_time_freq_hertz)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_transducer_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_transducer_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_timing_time_freq_hertz() {
        return uint_to_scaledFloat(this._edda_temperature_1_timing_time_freq_hertz, 0, 2000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_transducer_time_min_millisecond, value: this.get_edda_temperature_1_latency_edda_transducer_time_min_millisecond()})
        data.push({field: fields.edda_temperature_1_timing_time_freq_hertz, value: this.get_edda_temperature_1_timing_time_freq_hertz()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_transducer_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_timing_time_freq_hertz = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_11_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_11
        this._category = categories.none
        this._id = 101
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_timing_time_max_microsecond = 0
        this._edda_temperature_1_timing_time_min_microsecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_timing_time_max_microsecond(value) {
        this._edda_temperature_1_timing_time_max_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_temperature_1_timing_time_min_microsecond(value) {
        this._edda_temperature_1_timing_time_min_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_timing_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_timing_time_min_microsecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_timing_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_timing_time_max_microsecond, 0, 100000, 2)
    }
    get_edda_temperature_1_timing_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_timing_time_min_microsecond, 0, 100000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_timing_time_max_microsecond, value: this.get_edda_temperature_1_timing_time_max_microsecond()})
        data.push({field: fields.edda_temperature_1_timing_time_min_microsecond, value: this.get_edda_temperature_1_timing_time_min_microsecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_timing_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_timing_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_12_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_12
        this._category = categories.none
        this._id = 102
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_x_acceleration_max_gforce = 0
        this._edda_temperature_1_x_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_x_acceleration_max_gforce(value) {
        this._edda_temperature_1_x_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_1_x_acceleration_min_gforce(value) {
        this._edda_temperature_1_x_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_x_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_x_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_x_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_x_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_1_x_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_x_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_x_acceleration_max_gforce, value: this.get_edda_temperature_1_x_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_1_x_acceleration_min_gforce, value: this.get_edda_temperature_1_x_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_x_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_x_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_13_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_13
        this._category = categories.none
        this._id = 103
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_y_acceleration_max_gforce = 0
        this._edda_temperature_1_y_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_y_acceleration_max_gforce(value) {
        this._edda_temperature_1_y_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_1_y_acceleration_min_gforce(value) {
        this._edda_temperature_1_y_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_y_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_y_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_y_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_y_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_1_y_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_y_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_y_acceleration_max_gforce, value: this.get_edda_temperature_1_y_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_1_y_acceleration_min_gforce, value: this.get_edda_temperature_1_y_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_y_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_y_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_14_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_14
        this._category = categories.none
        this._id = 104
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_z_acceleration_max_gforce = 0
        this._edda_temperature_1_z_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_z_acceleration_max_gforce(value) {
        this._edda_temperature_1_z_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_1_z_acceleration_min_gforce(value) {
        this._edda_temperature_1_z_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_z_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_z_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_z_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_z_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_1_z_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_z_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_z_acceleration_max_gforce, value: this.get_edda_temperature_1_z_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_1_z_acceleration_min_gforce, value: this.get_edda_temperature_1_z_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_z_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_z_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_15_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_15
        this._category = categories.none
        this._id = 105
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_can_rx_size_rate_byte = 0
        this._edda_temperature_1_can_tx_size_rate_byte = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_can_rx_size_rate_byte(value) {
        this._edda_temperature_1_can_rx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    set_edda_temperature_1_can_tx_size_rate_byte(value) {
        this._edda_temperature_1_can_tx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_rx_size_rate_byte)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_can_tx_size_rate_byte)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_can_rx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_rx_size_rate_byte, 0, 125000, 2)
    }
    get_edda_temperature_1_can_tx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_temperature_1_can_tx_size_rate_byte, 0, 125000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_can_rx_size_rate_byte, value: this.get_edda_temperature_1_can_rx_size_rate_byte()})
        data.push({field: fields.edda_temperature_1_can_tx_size_rate_byte, value: this.get_edda_temperature_1_can_tx_size_rate_byte()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_can_rx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_can_tx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_16_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_16
        this._category = categories.none
        this._id = 106
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_controller_time_millisecond = 0
        this._edda_temperature_1_latency_edda_ground_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_controller_time_millisecond(value) {
        this._edda_temperature_1_latency_edda_controller_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_latency_edda_ground_time_millisecond(value) {
        this._edda_temperature_1_latency_edda_ground_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_controller_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_ground_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_controller_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_controller_time_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_latency_edda_ground_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_ground_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_controller_time_millisecond, value: this.get_edda_temperature_1_latency_edda_controller_time_millisecond()})
        data.push({field: fields.edda_temperature_1_latency_edda_ground_time_millisecond, value: this.get_edda_temperature_1_latency_edda_ground_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_controller_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_ground_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_17_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_17
        this._category = categories.none
        this._id = 107
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_latency_edda_temperature_2_time_millisecond = 0
        this._edda_temperature_1_latency_edda_transducer_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_latency_edda_temperature_2_time_millisecond(value) {
        this._edda_temperature_1_latency_edda_temperature_2_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_1_latency_edda_transducer_time_millisecond(value) {
        this._edda_temperature_1_latency_edda_transducer_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_temperature_2_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_latency_edda_transducer_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_latency_edda_temperature_2_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_temperature_2_time_millisecond, 0, 500, 2)
    }
    get_edda_temperature_1_latency_edda_transducer_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_latency_edda_transducer_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_latency_edda_temperature_2_time_millisecond, value: this.get_edda_temperature_1_latency_edda_temperature_2_time_millisecond()})
        data.push({field: fields.edda_temperature_1_latency_edda_transducer_time_millisecond, value: this.get_edda_temperature_1_latency_edda_transducer_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_latency_edda_temperature_2_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_latency_edda_transducer_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_18_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_18
        this._category = categories.none
        this._id = 108
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_timing_time_microsecond = 0
        this._edda_temperature_1_x_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_timing_time_microsecond(value) {
        this._edda_temperature_1_timing_time_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_temperature_1_x_acceleration_gforce(value) {
        this._edda_temperature_1_x_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_timing_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_x_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_timing_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_1_timing_time_microsecond, 0, 100000, 2)
    }
    get_edda_temperature_1_x_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_x_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_timing_time_microsecond, value: this.get_edda_temperature_1_timing_time_microsecond()})
        data.push({field: fields.edda_temperature_1_x_acceleration_gforce, value: this.get_edda_temperature_1_x_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_timing_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_x_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_19_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_19
        this._category = categories.none
        this._id = 109
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_y_acceleration_gforce = 0
        this._edda_temperature_1_z_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_y_acceleration_gforce(value) {
        this._edda_temperature_1_y_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_1_z_acceleration_gforce(value) {
        this._edda_temperature_1_z_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_1_y_acceleration_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_1_z_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_y_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_y_acceleration_gforce, -20, 20, 2)
    }
    get_edda_temperature_1_z_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_1_z_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_y_acceleration_gforce, value: this.get_edda_temperature_1_y_acceleration_gforce()})
        data.push({field: fields.edda_temperature_1_z_acceleration_gforce, value: this.get_edda_temperature_1_z_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_y_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_1_z_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_edda_temperature_1_20_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_edda_temperature_1_20
        this._category = categories.none
        this._id = 110
        this._size = 5
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_1_compensation_0_temperature_celsius = 0
        this._edda_temperature_1_compensation_1_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_1_compensation_0_temperature_celsius(value) {
        this._edda_temperature_1_compensation_0_temperature_celsius = packedFloat_to_uint(value, -20, 106, 1)
    }
    set_edda_temperature_1_compensation_1_temperature_celsius(value) {
        this._edda_temperature_1_compensation_1_temperature_celsius = packedFloat_to_uint(value, -20, 106, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<B").pack_into(buf, index, this._edda_temperature_1_compensation_0_temperature_celsius)
        index += 1
        struct("<B").pack_into(buf, index, this._edda_temperature_1_compensation_1_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_1_compensation_0_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_compensation_0_temperature_celsius, -20, 106, 1)
    }
    get_edda_temperature_1_compensation_1_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_1_compensation_1_temperature_celsius, -20, 106, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_1_compensation_0_temperature_celsius, value: this.get_edda_temperature_1_compensation_0_temperature_celsius()})
        data.push({field: fields.edda_temperature_1_compensation_1_temperature_celsius, value: this.get_edda_temperature_1_compensation_1_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_compensation_0_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_1_compensation_1_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_00_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_00
        this._category = categories.none
        this._id = 165
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_rtd_01_resistance_ohm = 0
        this._sindri_rtd_01_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_rtd_01_resistance_ohm(value) {
        this._sindri_rtd_01_resistance_ohm = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_sindri_rtd_01_voltage_volt(value) {
        this._sindri_rtd_01_voltage_volt = packedFloat_to_uint(value, 0, 5, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_rtd_01_resistance_ohm)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_rtd_01_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_rtd_01_resistance_ohm() {
        return uint_to_scaledFloat(this._sindri_rtd_01_resistance_ohm, 0, 10000, 2)
    }
    get_sindri_rtd_01_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_rtd_01_voltage_volt, 0, 5, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_rtd_01_resistance_ohm, value: this.get_sindri_rtd_01_resistance_ohm()})
        data.push({field: fields.sindri_rtd_01_voltage_volt, value: this.get_sindri_rtd_01_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_rtd_01_resistance_ohm = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_rtd_01_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_01_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_01
        this._category = categories.none
        this._id = 166
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_rtd_02_resistance_ohm = 0
        this._sindri_rtd_02_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_rtd_02_resistance_ohm(value) {
        this._sindri_rtd_02_resistance_ohm = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_sindri_rtd_02_voltage_volt(value) {
        this._sindri_rtd_02_voltage_volt = packedFloat_to_uint(value, 0, 5, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_rtd_02_resistance_ohm)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_rtd_02_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_rtd_02_resistance_ohm() {
        return uint_to_scaledFloat(this._sindri_rtd_02_resistance_ohm, 0, 10000, 2)
    }
    get_sindri_rtd_02_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_rtd_02_voltage_volt, 0, 5, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_rtd_02_resistance_ohm, value: this.get_sindri_rtd_02_resistance_ohm()})
        data.push({field: fields.sindri_rtd_02_voltage_volt, value: this.get_sindri_rtd_02_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_rtd_02_resistance_ohm = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_rtd_02_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_02_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_02
        this._category = categories.none
        this._id = 167
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_09_voltage_volt = 0
        this._sindri_therm_10_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_09_voltage_volt(value) {
        this._sindri_therm_09_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_10_voltage_volt(value) {
        this._sindri_therm_10_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_09_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_10_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_09_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_09_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_10_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_10_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_09_voltage_volt, value: this.get_sindri_therm_09_voltage_volt()})
        data.push({field: fields.sindri_therm_10_voltage_volt, value: this.get_sindri_therm_10_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_09_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_10_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_03_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_03
        this._category = categories.none
        this._id = 168
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_11_voltage_volt = 0
        this._sindri_therm_12_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_11_voltage_volt(value) {
        this._sindri_therm_11_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_12_voltage_volt(value) {
        this._sindri_therm_12_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_11_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_12_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_11_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_11_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_12_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_12_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_11_voltage_volt, value: this.get_sindri_therm_11_voltage_volt()})
        data.push({field: fields.sindri_therm_12_voltage_volt, value: this.get_sindri_therm_12_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_11_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_12_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_04_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_04
        this._category = categories.none
        this._id = 169
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_rtd_01_temperature_celsius = 0
        this._sindri_rtd_02_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_rtd_01_temperature_celsius(value) {
        this._sindri_rtd_01_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_rtd_02_temperature_celsius(value) {
        this._sindri_rtd_02_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_rtd_01_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_rtd_02_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_rtd_01_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_rtd_01_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_rtd_02_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_rtd_02_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_rtd_01_temperature_celsius, value: this.get_sindri_rtd_01_temperature_celsius()})
        data.push({field: fields.sindri_rtd_02_temperature_celsius, value: this.get_sindri_rtd_02_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_rtd_01_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_rtd_02_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_05_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_05
        this._category = categories.none
        this._id = 170
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_09_temperature_celsius = 0
        this._sindri_therm_10_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_09_temperature_celsius(value) {
        this._sindri_therm_09_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_10_temperature_celsius(value) {
        this._sindri_therm_10_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_09_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_10_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_09_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_09_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_10_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_10_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_09_temperature_celsius, value: this.get_sindri_therm_09_temperature_celsius()})
        data.push({field: fields.sindri_therm_10_temperature_celsius, value: this.get_sindri_therm_10_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_09_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_10_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard1_sindri_06_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard1_sindri_06
        this._category = categories.none
        this._id = 171
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_11_temperature_celsius = 0
        this._sindri_therm_12_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_11_temperature_celsius(value) {
        this._sindri_therm_11_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_12_temperature_celsius(value) {
        this._sindri_therm_12_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_11_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_12_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_11_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_11_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_12_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_12_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_11_temperature_celsius, value: this.get_sindri_therm_11_temperature_celsius()})
        data.push({field: fields.sindri_therm_12_temperature_celsius, value: this.get_sindri_therm_12_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_11_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_12_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_00_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_00
        this._category = categories.none
        this._id = 111
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_ambient_pressure_bar = 0
        this._edda_temperature_2_can_rx_time_max_microsecond = 0
        this._edda_temperature_2_board_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_ambient_pressure_bar(value) {
        this._edda_temperature_2_ambient_pressure_bar = packedFloat_to_uint(value, 0, 1.5, 2)
    }
    set_edda_temperature_2_can_rx_time_max_microsecond(value) {
        this._edda_temperature_2_can_rx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_board_temperature_celsius(value) {
        this._edda_temperature_2_board_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_ambient_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_rx_time_max_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_board_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_ambient_pressure_bar() {
        return uint_to_scaledFloat(this._edda_temperature_2_ambient_pressure_bar, 0, 1.5, 2)
    }
    get_edda_temperature_2_can_rx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_rx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_board_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_board_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_ambient_pressure_bar, value: this.get_edda_temperature_2_ambient_pressure_bar()})
        data.push({field: fields.edda_temperature_2_can_rx_time_max_microsecond, value: this.get_edda_temperature_2_can_rx_time_max_microsecond()})
        data.push({field: fields.edda_temperature_2_board_temperature_celsius, value: this.get_edda_temperature_2_board_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_ambient_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_can_rx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_board_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_01_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_01
        this._category = categories.none
        this._id = 112
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_can_rx_time_microsecond = 0
        this._edda_temperature_2_can_rx_time_min_microsecond = 0
        this._edda_temperature_2_humidity_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_can_rx_time_microsecond(value) {
        this._edda_temperature_2_can_rx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_can_rx_time_min_microsecond(value) {
        this._edda_temperature_2_can_rx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_humidity_sensor_temperature_celsius(value) {
        this._edda_temperature_2_humidity_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_rx_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_rx_time_min_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_humidity_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_can_rx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_rx_time_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_can_rx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_rx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_humidity_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_humidity_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_can_rx_time_microsecond, value: this.get_edda_temperature_2_can_rx_time_microsecond()})
        data.push({field: fields.edda_temperature_2_can_rx_time_min_microsecond, value: this.get_edda_temperature_2_can_rx_time_min_microsecond()})
        data.push({field: fields.edda_temperature_2_humidity_sensor_temperature_celsius, value: this.get_edda_temperature_2_humidity_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_can_rx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_can_rx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_humidity_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_02_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_02
        this._category = categories.none
        this._id = 113
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_can_tx_time_max_microsecond = 0
        this._edda_temperature_2_can_tx_time_microsecond = 0
        this._edda_temperature_2_imu_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_can_tx_time_max_microsecond(value) {
        this._edda_temperature_2_can_tx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_can_tx_time_microsecond(value) {
        this._edda_temperature_2_can_tx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_imu_temperature_celsius(value) {
        this._edda_temperature_2_imu_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_tx_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_tx_time_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_imu_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_can_tx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_tx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_can_tx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_tx_time_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_imu_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_imu_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_can_tx_time_max_microsecond, value: this.get_edda_temperature_2_can_tx_time_max_microsecond()})
        data.push({field: fields.edda_temperature_2_can_tx_time_microsecond, value: this.get_edda_temperature_2_can_tx_time_microsecond()})
        data.push({field: fields.edda_temperature_2_imu_temperature_celsius, value: this.get_edda_temperature_2_imu_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_can_tx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_can_tx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_imu_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_03_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_03
        this._category = categories.none
        this._id = 114
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_can_tx_time_min_microsecond = 0
        this._edda_temperature_2_input_current_ampere = 0
        this._edda_temperature_2_internal_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_can_tx_time_min_microsecond(value) {
        this._edda_temperature_2_can_tx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_temperature_2_input_current_ampere(value) {
        this._edda_temperature_2_input_current_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_2_internal_temperature_celsius(value) {
        this._edda_temperature_2_internal_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_tx_time_min_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_current_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_internal_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_can_tx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_tx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_temperature_2_input_current_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_current_ampere, -15, 15, 2)
    }
    get_edda_temperature_2_internal_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_internal_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_can_tx_time_min_microsecond, value: this.get_edda_temperature_2_can_tx_time_min_microsecond()})
        data.push({field: fields.edda_temperature_2_input_current_ampere, value: this.get_edda_temperature_2_input_current_ampere()})
        data.push({field: fields.edda_temperature_2_internal_temperature_celsius, value: this.get_edda_temperature_2_internal_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_can_tx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_input_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_internal_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_04_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_04
        this._category = categories.none
        this._id = 115
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_input_current_max_ampere = 0
        this._edda_temperature_2_input_current_min_ampere = 0
        this._edda_temperature_2_pressure_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_input_current_max_ampere(value) {
        this._edda_temperature_2_input_current_max_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_2_input_current_min_ampere(value) {
        this._edda_temperature_2_input_current_min_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_temperature_2_pressure_sensor_temperature_celsius(value) {
        this._edda_temperature_2_pressure_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_current_max_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_current_min_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_pressure_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_input_current_max_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_current_max_ampere, -15, 15, 2)
    }
    get_edda_temperature_2_input_current_min_ampere() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_current_min_ampere, -15, 15, 2)
    }
    get_edda_temperature_2_pressure_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_pressure_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_input_current_max_ampere, value: this.get_edda_temperature_2_input_current_max_ampere()})
        data.push({field: fields.edda_temperature_2_input_current_min_ampere, value: this.get_edda_temperature_2_input_current_min_ampere()})
        data.push({field: fields.edda_temperature_2_pressure_sensor_temperature_celsius, value: this.get_edda_temperature_2_pressure_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_input_current_max_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_input_current_min_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_pressure_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_05_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_05
        this._category = categories.none
        this._id = 116
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_input_voltage_max_volt = 0
        this._edda_temperature_2_input_voltage_min_volt = 0
        this._edda_temperature_2_relative_humidity_percentage = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_input_voltage_max_volt(value) {
        this._edda_temperature_2_input_voltage_max_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_2_input_voltage_min_volt(value) {
        this._edda_temperature_2_input_voltage_min_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_2_relative_humidity_percentage(value) {
        this._edda_temperature_2_relative_humidity_percentage = packedFloat_to_uint(value, 0, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_voltage_max_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_voltage_min_volt)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_temperature_2_relative_humidity_percentage)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_input_voltage_max_volt() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_voltage_max_volt, 0, 36, 2)
    }
    get_edda_temperature_2_input_voltage_min_volt() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_voltage_min_volt, 0, 36, 2)
    }
    get_edda_temperature_2_relative_humidity_percentage() {
        return uint_to_scaledFloat(this._edda_temperature_2_relative_humidity_percentage, 0, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_input_voltage_max_volt, value: this.get_edda_temperature_2_input_voltage_max_volt()})
        data.push({field: fields.edda_temperature_2_input_voltage_min_volt, value: this.get_edda_temperature_2_input_voltage_min_volt()})
        data.push({field: fields.edda_temperature_2_relative_humidity_percentage, value: this.get_edda_temperature_2_relative_humidity_percentage()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_input_voltage_max_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_input_voltage_min_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_relative_humidity_percentage = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_06_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_06
        this._category = categories.none
        this._id = 117
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_input_voltage_volt = 0
        this._edda_temperature_2_latency_edda_controller_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_input_voltage_volt(value) {
        this._edda_temperature_2_input_voltage_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_temperature_2_latency_edda_controller_time_max_millisecond(value) {
        this._edda_temperature_2_latency_edda_controller_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_input_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_controller_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_input_voltage_volt() {
        return uint_to_scaledFloat(this._edda_temperature_2_input_voltage_volt, 0, 36, 2)
    }
    get_edda_temperature_2_latency_edda_controller_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_controller_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_input_voltage_volt, value: this.get_edda_temperature_2_input_voltage_volt()})
        data.push({field: fields.edda_temperature_2_latency_edda_controller_time_max_millisecond, value: this.get_edda_temperature_2_latency_edda_controller_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_input_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_controller_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_07_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_07
        this._category = categories.none
        this._id = 118
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_controller_time_min_millisecond = 0
        this._edda_temperature_2_latency_edda_ground_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_controller_time_min_millisecond(value) {
        this._edda_temperature_2_latency_edda_controller_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_latency_edda_ground_time_max_millisecond(value) {
        this._edda_temperature_2_latency_edda_ground_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_controller_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_ground_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_controller_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_controller_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_latency_edda_ground_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_ground_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_controller_time_min_millisecond, value: this.get_edda_temperature_2_latency_edda_controller_time_min_millisecond()})
        data.push({field: fields.edda_temperature_2_latency_edda_ground_time_max_millisecond, value: this.get_edda_temperature_2_latency_edda_ground_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_controller_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_ground_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_08_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_08
        this._category = categories.none
        this._id = 119
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_ground_time_min_millisecond = 0
        this._edda_temperature_2_latency_edda_temperature_1_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_ground_time_min_millisecond(value) {
        this._edda_temperature_2_latency_edda_ground_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_latency_edda_temperature_1_time_max_millisecond(value) {
        this._edda_temperature_2_latency_edda_temperature_1_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_ground_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_temperature_1_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_ground_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_ground_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_latency_edda_temperature_1_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_temperature_1_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_ground_time_min_millisecond, value: this.get_edda_temperature_2_latency_edda_ground_time_min_millisecond()})
        data.push({field: fields.edda_temperature_2_latency_edda_temperature_1_time_max_millisecond, value: this.get_edda_temperature_2_latency_edda_temperature_1_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_ground_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_temperature_1_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_09_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_09
        this._category = categories.none
        this._id = 120
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_temperature_1_time_min_millisecond = 0
        this._edda_temperature_2_latency_edda_transducer_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_temperature_1_time_min_millisecond(value) {
        this._edda_temperature_2_latency_edda_temperature_1_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_latency_edda_transducer_time_max_millisecond(value) {
        this._edda_temperature_2_latency_edda_transducer_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_temperature_1_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_transducer_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_temperature_1_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_temperature_1_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_latency_edda_transducer_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_transducer_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_temperature_1_time_min_millisecond, value: this.get_edda_temperature_2_latency_edda_temperature_1_time_min_millisecond()})
        data.push({field: fields.edda_temperature_2_latency_edda_transducer_time_max_millisecond, value: this.get_edda_temperature_2_latency_edda_transducer_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_temperature_1_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_transducer_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_10_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_10
        this._category = categories.none
        this._id = 121
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_transducer_time_min_millisecond = 0
        this._edda_temperature_2_timing_time_freq_hertz = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_transducer_time_min_millisecond(value) {
        this._edda_temperature_2_latency_edda_transducer_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_timing_time_freq_hertz(value) {
        this._edda_temperature_2_timing_time_freq_hertz = packedFloat_to_uint(value, 0, 2000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_transducer_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_timing_time_freq_hertz)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_transducer_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_transducer_time_min_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_timing_time_freq_hertz() {
        return uint_to_scaledFloat(this._edda_temperature_2_timing_time_freq_hertz, 0, 2000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_transducer_time_min_millisecond, value: this.get_edda_temperature_2_latency_edda_transducer_time_min_millisecond()})
        data.push({field: fields.edda_temperature_2_timing_time_freq_hertz, value: this.get_edda_temperature_2_timing_time_freq_hertz()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_transducer_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_timing_time_freq_hertz = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_11_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_11
        this._category = categories.none
        this._id = 122
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_timing_time_max_microsecond = 0
        this._edda_temperature_2_timing_time_min_microsecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_timing_time_max_microsecond(value) {
        this._edda_temperature_2_timing_time_max_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_temperature_2_timing_time_min_microsecond(value) {
        this._edda_temperature_2_timing_time_min_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_timing_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_timing_time_min_microsecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_timing_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_timing_time_max_microsecond, 0, 100000, 2)
    }
    get_edda_temperature_2_timing_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_timing_time_min_microsecond, 0, 100000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_timing_time_max_microsecond, value: this.get_edda_temperature_2_timing_time_max_microsecond()})
        data.push({field: fields.edda_temperature_2_timing_time_min_microsecond, value: this.get_edda_temperature_2_timing_time_min_microsecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_timing_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_timing_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_12_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_12
        this._category = categories.none
        this._id = 123
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_x_acceleration_max_gforce = 0
        this._edda_temperature_2_x_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_x_acceleration_max_gforce(value) {
        this._edda_temperature_2_x_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_2_x_acceleration_min_gforce(value) {
        this._edda_temperature_2_x_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_x_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_x_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_x_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_x_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_2_x_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_x_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_x_acceleration_max_gforce, value: this.get_edda_temperature_2_x_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_2_x_acceleration_min_gforce, value: this.get_edda_temperature_2_x_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_x_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_x_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_13_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_13
        this._category = categories.none
        this._id = 124
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_y_acceleration_max_gforce = 0
        this._edda_temperature_2_y_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_y_acceleration_max_gforce(value) {
        this._edda_temperature_2_y_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_2_y_acceleration_min_gforce(value) {
        this._edda_temperature_2_y_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_y_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_y_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_y_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_y_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_2_y_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_y_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_y_acceleration_max_gforce, value: this.get_edda_temperature_2_y_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_2_y_acceleration_min_gforce, value: this.get_edda_temperature_2_y_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_y_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_y_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_14_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_14
        this._category = categories.none
        this._id = 125
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_z_acceleration_max_gforce = 0
        this._edda_temperature_2_z_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_z_acceleration_max_gforce(value) {
        this._edda_temperature_2_z_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_2_z_acceleration_min_gforce(value) {
        this._edda_temperature_2_z_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_z_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_z_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_z_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_z_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_temperature_2_z_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_z_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_z_acceleration_max_gforce, value: this.get_edda_temperature_2_z_acceleration_max_gforce()})
        data.push({field: fields.edda_temperature_2_z_acceleration_min_gforce, value: this.get_edda_temperature_2_z_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_z_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_z_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_15_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_15
        this._category = categories.none
        this._id = 126
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_can_rx_size_rate_byte = 0
        this._edda_temperature_2_can_tx_size_rate_byte = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_can_rx_size_rate_byte(value) {
        this._edda_temperature_2_can_rx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    set_edda_temperature_2_can_tx_size_rate_byte(value) {
        this._edda_temperature_2_can_tx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_rx_size_rate_byte)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_can_tx_size_rate_byte)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_can_rx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_rx_size_rate_byte, 0, 125000, 2)
    }
    get_edda_temperature_2_can_tx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_temperature_2_can_tx_size_rate_byte, 0, 125000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_can_rx_size_rate_byte, value: this.get_edda_temperature_2_can_rx_size_rate_byte()})
        data.push({field: fields.edda_temperature_2_can_tx_size_rate_byte, value: this.get_edda_temperature_2_can_tx_size_rate_byte()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_can_rx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_can_tx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_16_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_16
        this._category = categories.none
        this._id = 127
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_controller_time_millisecond = 0
        this._edda_temperature_2_latency_edda_ground_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_controller_time_millisecond(value) {
        this._edda_temperature_2_latency_edda_controller_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_latency_edda_ground_time_millisecond(value) {
        this._edda_temperature_2_latency_edda_ground_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_controller_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_ground_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_controller_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_controller_time_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_latency_edda_ground_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_ground_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_controller_time_millisecond, value: this.get_edda_temperature_2_latency_edda_controller_time_millisecond()})
        data.push({field: fields.edda_temperature_2_latency_edda_ground_time_millisecond, value: this.get_edda_temperature_2_latency_edda_ground_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_controller_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_ground_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_17_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_17
        this._category = categories.none
        this._id = 128
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_latency_edda_temperature_1_time_millisecond = 0
        this._edda_temperature_2_latency_edda_transducer_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_latency_edda_temperature_1_time_millisecond(value) {
        this._edda_temperature_2_latency_edda_temperature_1_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_temperature_2_latency_edda_transducer_time_millisecond(value) {
        this._edda_temperature_2_latency_edda_transducer_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_temperature_1_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_latency_edda_transducer_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_latency_edda_temperature_1_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_temperature_1_time_millisecond, 0, 500, 2)
    }
    get_edda_temperature_2_latency_edda_transducer_time_millisecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_latency_edda_transducer_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_latency_edda_temperature_1_time_millisecond, value: this.get_edda_temperature_2_latency_edda_temperature_1_time_millisecond()})
        data.push({field: fields.edda_temperature_2_latency_edda_transducer_time_millisecond, value: this.get_edda_temperature_2_latency_edda_transducer_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_latency_edda_temperature_1_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_latency_edda_transducer_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_18_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_18
        this._category = categories.none
        this._id = 129
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_timing_time_microsecond = 0
        this._edda_temperature_2_x_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_timing_time_microsecond(value) {
        this._edda_temperature_2_timing_time_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_temperature_2_x_acceleration_gforce(value) {
        this._edda_temperature_2_x_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_timing_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_x_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_timing_time_microsecond() {
        return uint_to_scaledFloat(this._edda_temperature_2_timing_time_microsecond, 0, 100000, 2)
    }
    get_edda_temperature_2_x_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_x_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_timing_time_microsecond, value: this.get_edda_temperature_2_timing_time_microsecond()})
        data.push({field: fields.edda_temperature_2_x_acceleration_gforce, value: this.get_edda_temperature_2_x_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_timing_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_x_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_19_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_19
        this._category = categories.none
        this._id = 130
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_y_acceleration_gforce = 0
        this._edda_temperature_2_z_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_y_acceleration_gforce(value) {
        this._edda_temperature_2_y_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_temperature_2_z_acceleration_gforce(value) {
        this._edda_temperature_2_z_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_temperature_2_y_acceleration_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_temperature_2_z_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_y_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_y_acceleration_gforce, -20, 20, 2)
    }
    get_edda_temperature_2_z_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_temperature_2_z_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_y_acceleration_gforce, value: this.get_edda_temperature_2_y_acceleration_gforce()})
        data.push({field: fields.edda_temperature_2_z_acceleration_gforce, value: this.get_edda_temperature_2_z_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_y_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_temperature_2_z_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_edda_temperature_2_20_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_edda_temperature_2_20
        this._category = categories.none
        this._id = 131
        this._size = 5
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_temperature_2_compensation_0_temperature_celsius = 0
        this._edda_temperature_2_compensation_1_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_temperature_2_compensation_0_temperature_celsius(value) {
        this._edda_temperature_2_compensation_0_temperature_celsius = packedFloat_to_uint(value, -20, 106, 1)
    }
    set_edda_temperature_2_compensation_1_temperature_celsius(value) {
        this._edda_temperature_2_compensation_1_temperature_celsius = packedFloat_to_uint(value, -20, 106, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(5)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<B").pack_into(buf, index, this._edda_temperature_2_compensation_0_temperature_celsius)
        index += 1
        struct("<B").pack_into(buf, index, this._edda_temperature_2_compensation_1_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_temperature_2_compensation_0_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_compensation_0_temperature_celsius, -20, 106, 1)
    }
    get_edda_temperature_2_compensation_1_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_temperature_2_compensation_1_temperature_celsius, -20, 106, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_temperature_2_compensation_0_temperature_celsius, value: this.get_edda_temperature_2_compensation_0_temperature_celsius()})
        data.push({field: fields.edda_temperature_2_compensation_1_temperature_celsius, value: this.get_edda_temperature_2_compensation_1_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_compensation_0_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_temperature_2_compensation_1_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_00_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_00
        this._category = categories.none
        this._id = 172
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_01_temperature_celsius = 0
        this._sindri_therm_02_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_01_temperature_celsius(value) {
        this._sindri_therm_01_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_02_temperature_celsius(value) {
        this._sindri_therm_02_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_01_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_02_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_01_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_01_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_02_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_02_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_01_temperature_celsius, value: this.get_sindri_therm_01_temperature_celsius()})
        data.push({field: fields.sindri_therm_02_temperature_celsius, value: this.get_sindri_therm_02_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_01_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_02_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_01_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_01
        this._category = categories.none
        this._id = 173
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_03_temperature_celsius = 0
        this._sindri_therm_04_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_03_temperature_celsius(value) {
        this._sindri_therm_03_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_04_temperature_celsius(value) {
        this._sindri_therm_04_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_03_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_04_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_03_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_03_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_04_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_04_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_03_temperature_celsius, value: this.get_sindri_therm_03_temperature_celsius()})
        data.push({field: fields.sindri_therm_04_temperature_celsius, value: this.get_sindri_therm_04_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_03_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_04_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_02_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_02
        this._category = categories.none
        this._id = 174
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_05_temperature_celsius = 0
        this._sindri_therm_06_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_05_temperature_celsius(value) {
        this._sindri_therm_05_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_06_temperature_celsius(value) {
        this._sindri_therm_06_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_05_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_06_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_05_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_05_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_06_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_06_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_05_temperature_celsius, value: this.get_sindri_therm_05_temperature_celsius()})
        data.push({field: fields.sindri_therm_06_temperature_celsius, value: this.get_sindri_therm_06_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_05_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_06_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_03_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_03
        this._category = categories.none
        this._id = 175
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_07_temperature_celsius = 0
        this._sindri_therm_08_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_07_temperature_celsius(value) {
        this._sindri_therm_07_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    set_sindri_therm_08_temperature_celsius(value) {
        this._sindri_therm_08_temperature_celsius = packedFloat_to_uint(value, -200, 1300, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_07_temperature_celsius)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_08_temperature_celsius)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_07_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_07_temperature_celsius, -200, 1300, 2)
    }
    get_sindri_therm_08_temperature_celsius() {
        return uint_to_scaledFloat(this._sindri_therm_08_temperature_celsius, -200, 1300, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_07_temperature_celsius, value: this.get_sindri_therm_07_temperature_celsius()})
        data.push({field: fields.sindri_therm_08_temperature_celsius, value: this.get_sindri_therm_08_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_07_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_08_temperature_celsius = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_04_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_04
        this._category = categories.none
        this._id = 176
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_01_voltage_volt = 0
        this._sindri_therm_02_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_01_voltage_volt(value) {
        this._sindri_therm_01_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_02_voltage_volt(value) {
        this._sindri_therm_02_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_01_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_02_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_01_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_01_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_02_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_02_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_01_voltage_volt, value: this.get_sindri_therm_01_voltage_volt()})
        data.push({field: fields.sindri_therm_02_voltage_volt, value: this.get_sindri_therm_02_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_01_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_02_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_05_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_05
        this._category = categories.none
        this._id = 177
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_03_voltage_volt = 0
        this._sindri_therm_04_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_03_voltage_volt(value) {
        this._sindri_therm_03_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_04_voltage_volt(value) {
        this._sindri_therm_04_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_03_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_04_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_03_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_03_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_04_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_04_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_03_voltage_volt, value: this.get_sindri_therm_03_voltage_volt()})
        data.push({field: fields.sindri_therm_04_voltage_volt, value: this.get_sindri_therm_04_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_03_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_04_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_06_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_06
        this._category = categories.none
        this._id = 178
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_05_voltage_volt = 0
        this._sindri_therm_06_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_05_voltage_volt(value) {
        this._sindri_therm_05_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_06_voltage_volt(value) {
        this._sindri_therm_06_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_05_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_06_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_05_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_05_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_06_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_06_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_05_voltage_volt, value: this.get_sindri_therm_05_voltage_volt()})
        data.push({field: fields.sindri_therm_06_voltage_volt, value: this.get_sindri_therm_06_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_05_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_06_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TemperatureBoard2_sindri_07_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TemperatureBoard2_sindri_07
        this._category = categories.none
        this._id = 179
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_therm_07_voltage_volt = 0
        this._sindri_therm_08_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_therm_07_voltage_volt(value) {
        this._sindri_therm_07_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    set_sindri_therm_08_voltage_volt(value) {
        this._sindri_therm_08_voltage_volt = packedFloat_to_uint(value, -0.1, 0.1, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_therm_07_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_therm_08_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_therm_07_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_07_voltage_volt, -0.1, 0.1, 2)
    }
    get_sindri_therm_08_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_therm_08_voltage_volt, -0.1, 0.1, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_therm_07_voltage_volt, value: this.get_sindri_therm_07_voltage_volt()})
        data.push({field: fields.sindri_therm_08_voltage_volt, value: this.get_sindri_therm_08_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_therm_07_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_therm_08_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_00_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_00
        this._category = categories.none
        this._id = 132
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_ambient_pressure_bar = 0
        this._edda_transducer_can_rx_time_max_microsecond = 0
        this._edda_transducer_board_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_ambient_pressure_bar(value) {
        this._edda_transducer_ambient_pressure_bar = packedFloat_to_uint(value, 0, 1.5, 2)
    }
    set_edda_transducer_can_rx_time_max_microsecond(value) {
        this._edda_transducer_can_rx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_board_temperature_celsius(value) {
        this._edda_transducer_board_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_ambient_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_can_rx_time_max_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_board_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_ambient_pressure_bar() {
        return uint_to_scaledFloat(this._edda_transducer_ambient_pressure_bar, 0, 1.5, 2)
    }
    get_edda_transducer_can_rx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_rx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_board_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_transducer_board_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_ambient_pressure_bar, value: this.get_edda_transducer_ambient_pressure_bar()})
        data.push({field: fields.edda_transducer_can_rx_time_max_microsecond, value: this.get_edda_transducer_can_rx_time_max_microsecond()})
        data.push({field: fields.edda_transducer_board_temperature_celsius, value: this.get_edda_transducer_board_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_ambient_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_can_rx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_board_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_01_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_01
        this._category = categories.none
        this._id = 133
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_can_rx_time_microsecond = 0
        this._edda_transducer_can_rx_time_min_microsecond = 0
        this._edda_transducer_humidity_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_can_rx_time_microsecond(value) {
        this._edda_transducer_can_rx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_can_rx_time_min_microsecond(value) {
        this._edda_transducer_can_rx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_humidity_sensor_temperature_celsius(value) {
        this._edda_transducer_humidity_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_can_rx_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_can_rx_time_min_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_humidity_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_can_rx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_rx_time_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_can_rx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_rx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_humidity_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_transducer_humidity_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_can_rx_time_microsecond, value: this.get_edda_transducer_can_rx_time_microsecond()})
        data.push({field: fields.edda_transducer_can_rx_time_min_microsecond, value: this.get_edda_transducer_can_rx_time_min_microsecond()})
        data.push({field: fields.edda_transducer_humidity_sensor_temperature_celsius, value: this.get_edda_transducer_humidity_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_can_rx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_can_rx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_humidity_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_02_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_02
        this._category = categories.none
        this._id = 134
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_can_tx_time_max_microsecond = 0
        this._edda_transducer_can_tx_time_microsecond = 0
        this._edda_transducer_imu_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_can_tx_time_max_microsecond(value) {
        this._edda_transducer_can_tx_time_max_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_can_tx_time_microsecond(value) {
        this._edda_transducer_can_tx_time_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_imu_temperature_celsius(value) {
        this._edda_transducer_imu_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_can_tx_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_can_tx_time_microsecond)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_imu_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_can_tx_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_tx_time_max_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_can_tx_time_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_tx_time_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_imu_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_transducer_imu_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_can_tx_time_max_microsecond, value: this.get_edda_transducer_can_tx_time_max_microsecond()})
        data.push({field: fields.edda_transducer_can_tx_time_microsecond, value: this.get_edda_transducer_can_tx_time_microsecond()})
        data.push({field: fields.edda_transducer_imu_temperature_celsius, value: this.get_edda_transducer_imu_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_can_tx_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_can_tx_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_imu_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_03_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_03
        this._category = categories.none
        this._id = 135
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_can_tx_time_min_microsecond = 0
        this._edda_transducer_input_current_ampere = 0
        this._edda_transducer_internal_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_can_tx_time_min_microsecond(value) {
        this._edda_transducer_can_tx_time_min_microsecond = packedFloat_to_uint(value, 0, 10000, 2)
    }
    set_edda_transducer_input_current_ampere(value) {
        this._edda_transducer_input_current_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_transducer_internal_temperature_celsius(value) {
        this._edda_transducer_internal_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_can_tx_time_min_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_input_current_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_internal_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_can_tx_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_can_tx_time_min_microsecond, 0, 10000, 2)
    }
    get_edda_transducer_input_current_ampere() {
        return uint_to_scaledFloat(this._edda_transducer_input_current_ampere, -15, 15, 2)
    }
    get_edda_transducer_internal_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_transducer_internal_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_can_tx_time_min_microsecond, value: this.get_edda_transducer_can_tx_time_min_microsecond()})
        data.push({field: fields.edda_transducer_input_current_ampere, value: this.get_edda_transducer_input_current_ampere()})
        data.push({field: fields.edda_transducer_internal_temperature_celsius, value: this.get_edda_transducer_internal_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_can_tx_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_input_current_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_internal_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_04_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_04
        this._category = categories.none
        this._id = 136
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_input_current_max_ampere = 0
        this._edda_transducer_input_current_min_ampere = 0
        this._edda_transducer_pressure_sensor_temperature_celsius = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_input_current_max_ampere(value) {
        this._edda_transducer_input_current_max_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_transducer_input_current_min_ampere(value) {
        this._edda_transducer_input_current_min_ampere = packedFloat_to_uint(value, -15, 15, 2)
    }
    set_edda_transducer_pressure_sensor_temperature_celsius(value) {
        this._edda_transducer_pressure_sensor_temperature_celsius = packedFloat_to_uint(value, -20, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_input_current_max_ampere)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_input_current_min_ampere)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_pressure_sensor_temperature_celsius)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_input_current_max_ampere() {
        return uint_to_scaledFloat(this._edda_transducer_input_current_max_ampere, -15, 15, 2)
    }
    get_edda_transducer_input_current_min_ampere() {
        return uint_to_scaledFloat(this._edda_transducer_input_current_min_ampere, -15, 15, 2)
    }
    get_edda_transducer_pressure_sensor_temperature_celsius() {
        return uint_to_scaledFloat(this._edda_transducer_pressure_sensor_temperature_celsius, -20, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_input_current_max_ampere, value: this.get_edda_transducer_input_current_max_ampere()})
        data.push({field: fields.edda_transducer_input_current_min_ampere, value: this.get_edda_transducer_input_current_min_ampere()})
        data.push({field: fields.edda_transducer_pressure_sensor_temperature_celsius, value: this.get_edda_transducer_pressure_sensor_temperature_celsius()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_input_current_max_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_input_current_min_ampere = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_pressure_sensor_temperature_celsius = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_05_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_05
        this._category = categories.none
        this._id = 137
        this._size = 8
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_input_voltage_max_volt = 0
        this._edda_transducer_input_voltage_min_volt = 0
        this._edda_transducer_relative_humidity_percentage = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_input_voltage_max_volt(value) {
        this._edda_transducer_input_voltage_max_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_transducer_input_voltage_min_volt(value) {
        this._edda_transducer_input_voltage_min_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_transducer_relative_humidity_percentage(value) {
        this._edda_transducer_relative_humidity_percentage = packedFloat_to_uint(value, 0, 100, 1)
    }
    build_buf() {
        let buf = new ArrayBuffer(8)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_input_voltage_max_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_input_voltage_min_volt)
        index += 2
        struct("<B").pack_into(buf, index, this._edda_transducer_relative_humidity_percentage)
        index += 1
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_input_voltage_max_volt() {
        return uint_to_scaledFloat(this._edda_transducer_input_voltage_max_volt, 0, 36, 2)
    }
    get_edda_transducer_input_voltage_min_volt() {
        return uint_to_scaledFloat(this._edda_transducer_input_voltage_min_volt, 0, 36, 2)
    }
    get_edda_transducer_relative_humidity_percentage() {
        return uint_to_scaledFloat(this._edda_transducer_relative_humidity_percentage, 0, 100, 1)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_input_voltage_max_volt, value: this.get_edda_transducer_input_voltage_max_volt()})
        data.push({field: fields.edda_transducer_input_voltage_min_volt, value: this.get_edda_transducer_input_voltage_min_volt()})
        data.push({field: fields.edda_transducer_relative_humidity_percentage, value: this.get_edda_transducer_relative_humidity_percentage()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_input_voltage_max_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_input_voltage_min_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_relative_humidity_percentage = struct("<B").unpack_from(buf, index)[0]
        index += 1
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_06_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_06
        this._category = categories.none
        this._id = 138
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_input_voltage_volt = 0
        this._edda_transducer_latency_edda_controller_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_input_voltage_volt(value) {
        this._edda_transducer_input_voltage_volt = packedFloat_to_uint(value, 0, 36, 2)
    }
    set_edda_transducer_latency_edda_controller_time_max_millisecond(value) {
        this._edda_transducer_latency_edda_controller_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_input_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_controller_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_input_voltage_volt() {
        return uint_to_scaledFloat(this._edda_transducer_input_voltage_volt, 0, 36, 2)
    }
    get_edda_transducer_latency_edda_controller_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_controller_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_input_voltage_volt, value: this.get_edda_transducer_input_voltage_volt()})
        data.push({field: fields.edda_transducer_latency_edda_controller_time_max_millisecond, value: this.get_edda_transducer_latency_edda_controller_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_input_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_controller_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_07_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_07
        this._category = categories.none
        this._id = 139
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_controller_time_min_millisecond = 0
        this._edda_transducer_latency_edda_ground_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_controller_time_min_millisecond(value) {
        this._edda_transducer_latency_edda_controller_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_latency_edda_ground_time_max_millisecond(value) {
        this._edda_transducer_latency_edda_ground_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_controller_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_ground_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_controller_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_controller_time_min_millisecond, 0, 500, 2)
    }
    get_edda_transducer_latency_edda_ground_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_ground_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_controller_time_min_millisecond, value: this.get_edda_transducer_latency_edda_controller_time_min_millisecond()})
        data.push({field: fields.edda_transducer_latency_edda_ground_time_max_millisecond, value: this.get_edda_transducer_latency_edda_ground_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_controller_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_ground_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_08_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_08
        this._category = categories.none
        this._id = 140
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_ground_time_min_millisecond = 0
        this._edda_transducer_latency_edda_temperature_1_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_ground_time_min_millisecond(value) {
        this._edda_transducer_latency_edda_ground_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_latency_edda_temperature_1_time_max_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_1_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_ground_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_1_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_ground_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_ground_time_min_millisecond, 0, 500, 2)
    }
    get_edda_transducer_latency_edda_temperature_1_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_1_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_ground_time_min_millisecond, value: this.get_edda_transducer_latency_edda_ground_time_min_millisecond()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_1_time_max_millisecond, value: this.get_edda_transducer_latency_edda_temperature_1_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_ground_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_temperature_1_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_09_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_09
        this._category = categories.none
        this._id = 141
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_temperature_1_time_min_millisecond = 0
        this._edda_transducer_latency_edda_temperature_2_time_max_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_temperature_1_time_min_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_1_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_latency_edda_temperature_2_time_max_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_2_time_max_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_1_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_2_time_max_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_temperature_1_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_1_time_min_millisecond, 0, 500, 2)
    }
    get_edda_transducer_latency_edda_temperature_2_time_max_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_2_time_max_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_1_time_min_millisecond, value: this.get_edda_transducer_latency_edda_temperature_1_time_min_millisecond()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_2_time_max_millisecond, value: this.get_edda_transducer_latency_edda_temperature_2_time_max_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_temperature_1_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_temperature_2_time_max_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_10_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_10
        this._category = categories.none
        this._id = 142
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_temperature_2_time_min_millisecond = 0
        this._edda_transducer_timing_time_freq_hertz = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_temperature_2_time_min_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_2_time_min_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_timing_time_freq_hertz(value) {
        this._edda_transducer_timing_time_freq_hertz = packedFloat_to_uint(value, 0, 2000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_2_time_min_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_timing_time_freq_hertz)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_temperature_2_time_min_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_2_time_min_millisecond, 0, 500, 2)
    }
    get_edda_transducer_timing_time_freq_hertz() {
        return uint_to_scaledFloat(this._edda_transducer_timing_time_freq_hertz, 0, 2000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_2_time_min_millisecond, value: this.get_edda_transducer_latency_edda_temperature_2_time_min_millisecond()})
        data.push({field: fields.edda_transducer_timing_time_freq_hertz, value: this.get_edda_transducer_timing_time_freq_hertz()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_temperature_2_time_min_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_timing_time_freq_hertz = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_11_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_11
        this._category = categories.none
        this._id = 143
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_timing_time_max_microsecond = 0
        this._edda_transducer_timing_time_min_microsecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_timing_time_max_microsecond(value) {
        this._edda_transducer_timing_time_max_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_transducer_timing_time_min_microsecond(value) {
        this._edda_transducer_timing_time_min_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_timing_time_max_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_timing_time_min_microsecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_timing_time_max_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_timing_time_max_microsecond, 0, 100000, 2)
    }
    get_edda_transducer_timing_time_min_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_timing_time_min_microsecond, 0, 100000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_timing_time_max_microsecond, value: this.get_edda_transducer_timing_time_max_microsecond()})
        data.push({field: fields.edda_transducer_timing_time_min_microsecond, value: this.get_edda_transducer_timing_time_min_microsecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_timing_time_max_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_timing_time_min_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_12_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_12
        this._category = categories.none
        this._id = 144
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_x_acceleration_max_gforce = 0
        this._edda_transducer_x_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_x_acceleration_max_gforce(value) {
        this._edda_transducer_x_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_transducer_x_acceleration_min_gforce(value) {
        this._edda_transducer_x_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_x_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_x_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_x_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_x_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_transducer_x_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_x_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_x_acceleration_max_gforce, value: this.get_edda_transducer_x_acceleration_max_gforce()})
        data.push({field: fields.edda_transducer_x_acceleration_min_gforce, value: this.get_edda_transducer_x_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_x_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_x_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_13_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_13
        this._category = categories.none
        this._id = 145
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_y_acceleration_max_gforce = 0
        this._edda_transducer_y_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_y_acceleration_max_gforce(value) {
        this._edda_transducer_y_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_transducer_y_acceleration_min_gforce(value) {
        this._edda_transducer_y_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_y_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_y_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_y_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_y_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_transducer_y_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_y_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_y_acceleration_max_gforce, value: this.get_edda_transducer_y_acceleration_max_gforce()})
        data.push({field: fields.edda_transducer_y_acceleration_min_gforce, value: this.get_edda_transducer_y_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_y_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_y_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_14_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_14
        this._category = categories.none
        this._id = 146
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_z_acceleration_max_gforce = 0
        this._edda_transducer_z_acceleration_min_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_z_acceleration_max_gforce(value) {
        this._edda_transducer_z_acceleration_max_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_transducer_z_acceleration_min_gforce(value) {
        this._edda_transducer_z_acceleration_min_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_z_acceleration_max_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_z_acceleration_min_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_z_acceleration_max_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_z_acceleration_max_gforce, -20, 20, 2)
    }
    get_edda_transducer_z_acceleration_min_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_z_acceleration_min_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_z_acceleration_max_gforce, value: this.get_edda_transducer_z_acceleration_max_gforce()})
        data.push({field: fields.edda_transducer_z_acceleration_min_gforce, value: this.get_edda_transducer_z_acceleration_min_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_z_acceleration_max_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_z_acceleration_min_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_15_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_15
        this._category = categories.none
        this._id = 147
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_can_rx_size_rate_byte = 0
        this._edda_transducer_can_tx_size_rate_byte = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_can_rx_size_rate_byte(value) {
        this._edda_transducer_can_rx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    set_edda_transducer_can_tx_size_rate_byte(value) {
        this._edda_transducer_can_tx_size_rate_byte = packedFloat_to_uint(value, 0, 125000, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_can_rx_size_rate_byte)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_can_tx_size_rate_byte)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_can_rx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_transducer_can_rx_size_rate_byte, 0, 125000, 2)
    }
    get_edda_transducer_can_tx_size_rate_byte() {
        return uint_to_scaledFloat(this._edda_transducer_can_tx_size_rate_byte, 0, 125000, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_can_rx_size_rate_byte, value: this.get_edda_transducer_can_rx_size_rate_byte()})
        data.push({field: fields.edda_transducer_can_tx_size_rate_byte, value: this.get_edda_transducer_can_tx_size_rate_byte()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_can_rx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_can_tx_size_rate_byte = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_16_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_16
        this._category = categories.none
        this._id = 148
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_controller_time_millisecond = 0
        this._edda_transducer_latency_edda_ground_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_controller_time_millisecond(value) {
        this._edda_transducer_latency_edda_controller_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_latency_edda_ground_time_millisecond(value) {
        this._edda_transducer_latency_edda_ground_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_controller_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_ground_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_controller_time_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_controller_time_millisecond, 0, 500, 2)
    }
    get_edda_transducer_latency_edda_ground_time_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_ground_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_controller_time_millisecond, value: this.get_edda_transducer_latency_edda_controller_time_millisecond()})
        data.push({field: fields.edda_transducer_latency_edda_ground_time_millisecond, value: this.get_edda_transducer_latency_edda_ground_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_controller_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_ground_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_17_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_17
        this._category = categories.none
        this._id = 149
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_latency_edda_temperature_1_time_millisecond = 0
        this._edda_transducer_latency_edda_temperature_2_time_millisecond = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_latency_edda_temperature_1_time_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_1_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    set_edda_transducer_latency_edda_temperature_2_time_millisecond(value) {
        this._edda_transducer_latency_edda_temperature_2_time_millisecond = packedFloat_to_uint(value, 0, 500, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_1_time_millisecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_latency_edda_temperature_2_time_millisecond)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_latency_edda_temperature_1_time_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_1_time_millisecond, 0, 500, 2)
    }
    get_edda_transducer_latency_edda_temperature_2_time_millisecond() {
        return uint_to_scaledFloat(this._edda_transducer_latency_edda_temperature_2_time_millisecond, 0, 500, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_1_time_millisecond, value: this.get_edda_transducer_latency_edda_temperature_1_time_millisecond()})
        data.push({field: fields.edda_transducer_latency_edda_temperature_2_time_millisecond, value: this.get_edda_transducer_latency_edda_temperature_2_time_millisecond()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_latency_edda_temperature_1_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_latency_edda_temperature_2_time_millisecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_18_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_18
        this._category = categories.none
        this._id = 150
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_timing_time_microsecond = 0
        this._edda_transducer_x_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_timing_time_microsecond(value) {
        this._edda_transducer_timing_time_microsecond = packedFloat_to_uint(value, 0, 100000, 2)
    }
    set_edda_transducer_x_acceleration_gforce(value) {
        this._edda_transducer_x_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_timing_time_microsecond)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_x_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_timing_time_microsecond() {
        return uint_to_scaledFloat(this._edda_transducer_timing_time_microsecond, 0, 100000, 2)
    }
    get_edda_transducer_x_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_x_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_timing_time_microsecond, value: this.get_edda_transducer_timing_time_microsecond()})
        data.push({field: fields.edda_transducer_x_acceleration_gforce, value: this.get_edda_transducer_x_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_timing_time_microsecond = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_x_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_edda_transducer_19_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_edda_transducer_19
        this._category = categories.none
        this._id = 151
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._edda_transducer_y_acceleration_gforce = 0
        this._edda_transducer_z_acceleration_gforce = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_edda_transducer_y_acceleration_gforce(value) {
        this._edda_transducer_y_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    set_edda_transducer_z_acceleration_gforce(value) {
        this._edda_transducer_z_acceleration_gforce = packedFloat_to_uint(value, -20, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._edda_transducer_y_acceleration_gforce)
        index += 2
        struct("<H").pack_into(buf, index, this._edda_transducer_z_acceleration_gforce)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_edda_transducer_y_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_y_acceleration_gforce, -20, 20, 2)
    }
    get_edda_transducer_z_acceleration_gforce() {
        return uint_to_scaledFloat(this._edda_transducer_z_acceleration_gforce, -20, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.edda_transducer_y_acceleration_gforce, value: this.get_edda_transducer_y_acceleration_gforce()})
        data.push({field: fields.edda_transducer_z_acceleration_gforce, value: this.get_edda_transducer_z_acceleration_gforce()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._edda_transducer_y_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._edda_transducer_z_acceleration_gforce = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_00_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_00
        this._category = categories.none
        this._id = 180
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_01_pressure_bar = 0
        this._sindri_transducer_04_pressure_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_01_pressure_bar(value) {
        this._sindri_transducer_01_pressure_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_04_pressure_bar(value) {
        this._sindri_transducer_04_pressure_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_01_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_04_pressure_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_01_pressure_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_01_pressure_bar, -10, 100, 2)
    }
    get_sindri_transducer_04_pressure_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_04_pressure_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_01_pressure_bar, value: this.get_sindri_transducer_01_pressure_bar()})
        data.push({field: fields.sindri_transducer_04_pressure_bar, value: this.get_sindri_transducer_04_pressure_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_01_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_04_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_01_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_01
        this._category = categories.none
        this._id = 181
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_01_pressure_max_bar = 0
        this._sindri_transducer_01_pressure_min_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_01_pressure_max_bar(value) {
        this._sindri_transducer_01_pressure_max_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_01_pressure_min_bar(value) {
        this._sindri_transducer_01_pressure_min_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_01_pressure_max_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_01_pressure_min_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_01_pressure_max_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_01_pressure_max_bar, -10, 100, 2)
    }
    get_sindri_transducer_01_pressure_min_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_01_pressure_min_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_01_pressure_max_bar, value: this.get_sindri_transducer_01_pressure_max_bar()})
        data.push({field: fields.sindri_transducer_01_pressure_min_bar, value: this.get_sindri_transducer_01_pressure_min_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_01_pressure_max_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_01_pressure_min_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_02_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_02
        this._category = categories.none
        this._id = 182
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_02_pressure_max_bar = 0
        this._sindri_transducer_02_pressure_min_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_02_pressure_max_bar(value) {
        this._sindri_transducer_02_pressure_max_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_02_pressure_min_bar(value) {
        this._sindri_transducer_02_pressure_min_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_02_pressure_max_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_02_pressure_min_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_02_pressure_max_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_02_pressure_max_bar, -10, 100, 2)
    }
    get_sindri_transducer_02_pressure_min_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_02_pressure_min_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_02_pressure_max_bar, value: this.get_sindri_transducer_02_pressure_max_bar()})
        data.push({field: fields.sindri_transducer_02_pressure_min_bar, value: this.get_sindri_transducer_02_pressure_min_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_02_pressure_max_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_02_pressure_min_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_03_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_03
        this._category = categories.none
        this._id = 183
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_03_pressure_max_bar = 0
        this._sindri_transducer_03_pressure_min_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_03_pressure_max_bar(value) {
        this._sindri_transducer_03_pressure_max_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_03_pressure_min_bar(value) {
        this._sindri_transducer_03_pressure_min_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_03_pressure_max_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_03_pressure_min_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_03_pressure_max_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_03_pressure_max_bar, -10, 100, 2)
    }
    get_sindri_transducer_03_pressure_min_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_03_pressure_min_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_03_pressure_max_bar, value: this.get_sindri_transducer_03_pressure_max_bar()})
        data.push({field: fields.sindri_transducer_03_pressure_min_bar, value: this.get_sindri_transducer_03_pressure_min_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_03_pressure_max_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_03_pressure_min_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_04_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_04
        this._category = categories.none
        this._id = 184
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_04_pressure_max_bar = 0
        this._sindri_transducer_04_pressure_min_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_04_pressure_max_bar(value) {
        this._sindri_transducer_04_pressure_max_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_04_pressure_min_bar(value) {
        this._sindri_transducer_04_pressure_min_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_04_pressure_max_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_04_pressure_min_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_04_pressure_max_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_04_pressure_max_bar, -10, 100, 2)
    }
    get_sindri_transducer_04_pressure_min_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_04_pressure_min_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_04_pressure_max_bar, value: this.get_sindri_transducer_04_pressure_max_bar()})
        data.push({field: fields.sindri_transducer_04_pressure_min_bar, value: this.get_sindri_transducer_04_pressure_min_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_04_pressure_max_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_04_pressure_min_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_05_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_05
        this._category = categories.none
        this._id = 185
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_01_voltage_volt = 0
        this._sindri_transducer_02_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_01_voltage_volt(value) {
        this._sindri_transducer_01_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    set_sindri_transducer_02_voltage_volt(value) {
        this._sindri_transducer_02_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_01_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_02_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_01_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_01_voltage_volt, 0, 10, 2)
    }
    get_sindri_transducer_02_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_02_voltage_volt, 0, 10, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_01_voltage_volt, value: this.get_sindri_transducer_01_voltage_volt()})
        data.push({field: fields.sindri_transducer_02_voltage_volt, value: this.get_sindri_transducer_02_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_01_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_02_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_06_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_06
        this._category = categories.none
        this._id = 186
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_03_voltage_volt = 0
        this._sindri_transducer_04_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_03_voltage_volt(value) {
        this._sindri_transducer_03_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    set_sindri_transducer_04_voltage_volt(value) {
        this._sindri_transducer_04_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_03_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_04_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_03_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_03_voltage_volt, 0, 10, 2)
    }
    get_sindri_transducer_04_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_04_voltage_volt, 0, 10, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_03_voltage_volt, value: this.get_sindri_transducer_03_voltage_volt()})
        data.push({field: fields.sindri_transducer_04_voltage_volt, value: this.get_sindri_transducer_04_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_03_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_04_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_07_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_07
        this._category = categories.none
        this._id = 187
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_05_voltage_volt = 0
        this._sindri_transducer_06_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_05_voltage_volt(value) {
        this._sindri_transducer_05_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    set_sindri_transducer_06_voltage_volt(value) {
        this._sindri_transducer_06_voltage_volt = packedFloat_to_uint(value, 0, 10, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_05_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_06_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_05_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_05_voltage_volt, 0, 10, 2)
    }
    get_sindri_transducer_06_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_06_voltage_volt, 0, 10, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_05_voltage_volt, value: this.get_sindri_transducer_05_voltage_volt()})
        data.push({field: fields.sindri_transducer_06_voltage_volt, value: this.get_sindri_transducer_06_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_05_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_06_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_08_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_08
        this._category = categories.none
        this._id = 188
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_02_pressure_bar = 0
        this._sindri_transducer_03_pressure_bar = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_02_pressure_bar(value) {
        this._sindri_transducer_02_pressure_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    set_sindri_transducer_03_pressure_bar(value) {
        this._sindri_transducer_03_pressure_bar = packedFloat_to_uint(value, -10, 100, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_02_pressure_bar)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_03_pressure_bar)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_02_pressure_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_02_pressure_bar, -10, 100, 2)
    }
    get_sindri_transducer_03_pressure_bar() {
        return uint_to_scaledFloat(this._sindri_transducer_03_pressure_bar, -10, 100, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_02_pressure_bar, value: this.get_sindri_transducer_02_pressure_bar()})
        data.push({field: fields.sindri_transducer_03_pressure_bar, value: this.get_sindri_transducer_03_pressure_bar()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_02_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_03_pressure_bar = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class Telemetry__TransducerBoard_sindri_09_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.Telemetry__TransducerBoard_sindri_09
        this._category = categories.none
        this._id = 189
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._sindri_transducer_12v_voltage_volt = 0
        this._sindri_transducer_5v_voltage_volt = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_sindri_transducer_12v_voltage_volt(value) {
        this._sindri_transducer_12v_voltage_volt = packedFloat_to_uint(value, 0, 20, 2)
    }
    set_sindri_transducer_5v_voltage_volt(value) {
        this._sindri_transducer_5v_voltage_volt = packedFloat_to_uint(value, 0, 20, 2)
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<H").pack_into(buf, index, this._sindri_transducer_12v_voltage_volt)
        index += 2
        struct("<H").pack_into(buf, index, this._sindri_transducer_5v_voltage_volt)
        index += 2
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_sindri_transducer_12v_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_12v_voltage_volt, 0, 20, 2)
    }
    get_sindri_transducer_5v_voltage_volt() {
        return uint_to_scaledFloat(this._sindri_transducer_5v_voltage_volt, 0, 20, 2)
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.sindri_transducer_12v_voltage_volt, value: this.get_sindri_transducer_12v_voltage_volt()})
        data.push({field: fields.sindri_transducer_5v_voltage_volt, value: this.get_sindri_transducer_5v_voltage_volt()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._sindri_transducer_12v_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._sindri_transducer_5v_voltage_volt = struct("<H").unpack_from(buf, index)[0]
        index += 2
        return
    }
}
export class TelemetryMetaFrame_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaFrame
        this._category = categories.none
        this._id = 42
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._frame_number = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_frame_number(value) {
        this._frame_number = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._frame_number)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_frame_number() {
        return this._frame_number
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.frame_number, value: this.get_frame_number()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._frame_number = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaFrame_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaFrame
        this._category = categories.none
        this._id = 40
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._frame_number = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_frame_number(value) {
        this._frame_number = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._frame_number)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_frame_number() {
        return this._frame_number
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.frame_number, value: this.get_frame_number()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._frame_number = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaFrame_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaFrame
        this._category = categories.none
        this._id = 46
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._frame_number = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_frame_number(value) {
        this._frame_number = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._frame_number)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_frame_number() {
        return this._frame_number
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.frame_number, value: this.get_frame_number()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._frame_number = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaFrame_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaFrame
        this._category = categories.none
        this._id = 48
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._frame_number = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_frame_number(value) {
        this._frame_number = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._frame_number)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_frame_number() {
        return this._frame_number
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.frame_number, value: this.get_frame_number()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._frame_number = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaFrame_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaFrame
        this._category = categories.none
        this._id = 44
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._frame_number = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_frame_number(value) {
        this._frame_number = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._frame_number)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_frame_number() {
        return this._frame_number
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.frame_number, value: this.get_frame_number()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._frame_number = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaTime_from_Controller_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Controller_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaTime
        this._category = categories.none
        this._id = 43
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._time_since_boot_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_time_since_boot_ms(value) {
        this._time_since_boot_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._time_since_boot_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_time_since_boot_ms() {
        return this._time_since_boot_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.time_since_boot_ms, value: this.get_time_since_boot_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_since_boot_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaTime_from_Ground_Controller_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Ground_Controller
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaTime
        this._category = categories.none
        this._id = 41
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._time_since_boot_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_time_since_boot_ms(value) {
        this._time_since_boot_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._time_since_boot_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_time_since_boot_ms() {
        return this._time_since_boot_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.time_since_boot_ms, value: this.get_time_since_boot_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_since_boot_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaTime_from_Temperature_Board_1_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_1
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaTime
        this._category = categories.none
        this._id = 47
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._time_since_boot_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_time_since_boot_ms(value) {
        this._time_since_boot_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._time_since_boot_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_time_since_boot_ms() {
        return this._time_since_boot_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.time_since_boot_ms, value: this.get_time_since_boot_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_since_boot_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaTime_from_Temperature_Board_2_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Temperature_Board_2
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaTime
        this._category = categories.none
        this._id = 49
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._time_since_boot_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_time_since_boot_ms(value) {
        this._time_since_boot_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._time_since_boot_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_time_since_boot_ms() {
        return this._time_since_boot_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.time_since_boot_ms, value: this.get_time_since_boot_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_since_boot_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export class TelemetryMetaTime_from_Transducer_Board_to_Ground_Controller {
    constructor() {
        this._sender = nodes.Transducer_Board
        this._receiver = nodes.Ground_Controller
        this._message = messages.TelemetryMetaTime
        this._category = categories.none
        this._id = 45
        this._size = 7
        this._checksum = 0
        this._truncated_frame_number = 0
        this._time_since_boot_ms = 0
    }
    get_sender() { return this._sender }
    get_receiver() { return this._receiver }
    get_message() { return this._message }
    get_id() { return this._id }
    get_size() { return this._size }
    get_category() { return this._category }
    set_checksum(value) {
        this._checksum = value
    }
    set_truncated_frame_number(value) {
        this._truncated_frame_number = value
    }
    set_time_since_boot_ms(value) {
        this._time_since_boot_ms = value
    }
    build_buf() {
        let buf = new ArrayBuffer(7)
        let index = 0
        struct("<H").pack_into(buf, index, this._checksum)
        index += 2
        struct("<B").pack_into(buf, index, this._truncated_frame_number)
        index += 1
        struct("<L").pack_into(buf, index, this._time_since_boot_ms)
        index += 4
        return buf
    }
    get_checksum() {
        return this._checksum
    }
    get_truncated_frame_number() {
        return this._truncated_frame_number
    }
    get_time_since_boot_ms() {
        return this._time_since_boot_ms
    }
    get_all_data() {
        data = []
        data.push({field: fields.checksum, value: this.get_checksum()})
        data.push({field: fields.truncated_frame_number, value: this.get_truncated_frame_number()})
        data.push({field: fields.time_since_boot_ms, value: this.get_time_since_boot_ms()})
        return data
    }
    parse_buf(buf) {
        let index = 0
        this._checksum = struct("<H").unpack_from(buf, index)[0]
        index += 2
        this._truncated_frame_number = struct("<B").unpack_from(buf, index)[0]
        index += 1
        this._time_since_boot_ms = struct("<L").unpack_from(buf, index)[0]
        index += 4
        return
    }
}
export function id_to_message_class(id) {
    if (id == 35) {
        receiver = ChannelState_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 33) {
        receiver = ChannelTransitionRequest_from_Ground_Controller_to_Controller_Board()
        return receiver
    }
    if (id == 34) {
        receiver = ChannelTransitionResponse_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 36) {
        receiver = Countdown_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 38) {
        receiver = EngineActionRequest_from_Ground_Controller_to_Controller_Board()
        return receiver
    }
    if (id == 39) {
        receiver = EngineActionResponse_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 37) {
        receiver = EngineState_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 0) {
        receiver = Heartbeat_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 4) {
        receiver = Heartbeat_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 5) {
        receiver = Heartbeat_from_Power_Channel_1_to_Ground_Controller()
        return receiver
    }
    if (id == 6) {
        receiver = Heartbeat_from_Power_Channel_2_to_Ground_Controller()
        return receiver
    }
    if (id == 7) {
        receiver = Heartbeat_from_Power_Channel_3_to_Ground_Controller()
        return receiver
    }
    if (id == 1) {
        receiver = Heartbeat_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 2) {
        receiver = Heartbeat_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 3) {
        receiver = Heartbeat_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 18) {
        receiver = Latency_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 22) {
        receiver = Latency_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 19) {
        receiver = Latency_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 20) {
        receiver = Latency_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 21) {
        receiver = Latency_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 8) {
        receiver = Ping_from_Controller_Board_to_Controller_Board()
        return receiver
    }
    if (id == 8) {
        receiver = Ping_from_Controller_Board_to_Temperature_Board_1()
        return receiver
    }
    if (id == 8) {
        receiver = Ping_from_Controller_Board_to_Temperature_Board_2()
        return receiver
    }
    if (id == 8) {
        receiver = Ping_from_Controller_Board_to_Transducer_Board()
        return receiver
    }
    if (id == 8) {
        receiver = Ping_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 12) {
        receiver = Ping_from_Ground_Controller_to_Controller_Board()
        return receiver
    }
    if (id == 12) {
        receiver = Ping_from_Ground_Controller_to_Temperature_Board_1()
        return receiver
    }
    if (id == 12) {
        receiver = Ping_from_Ground_Controller_to_Temperature_Board_2()
        return receiver
    }
    if (id == 12) {
        receiver = Ping_from_Ground_Controller_to_Transducer_Board()
        return receiver
    }
    if (id == 12) {
        receiver = Ping_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 9) {
        receiver = Ping_from_Temperature_Board_1_to_Controller_Board()
        return receiver
    }
    if (id == 9) {
        receiver = Ping_from_Temperature_Board_1_to_Temperature_Board_1()
        return receiver
    }
    if (id == 9) {
        receiver = Ping_from_Temperature_Board_1_to_Temperature_Board_2()
        return receiver
    }
    if (id == 9) {
        receiver = Ping_from_Temperature_Board_1_to_Transducer_Board()
        return receiver
    }
    if (id == 9) {
        receiver = Ping_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 10) {
        receiver = Ping_from_Temperature_Board_2_to_Controller_Board()
        return receiver
    }
    if (id == 10) {
        receiver = Ping_from_Temperature_Board_2_to_Temperature_Board_1()
        return receiver
    }
    if (id == 10) {
        receiver = Ping_from_Temperature_Board_2_to_Temperature_Board_2()
        return receiver
    }
    if (id == 10) {
        receiver = Ping_from_Temperature_Board_2_to_Transducer_Board()
        return receiver
    }
    if (id == 10) {
        receiver = Ping_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 11) {
        receiver = Ping_from_Transducer_Board_to_Controller_Board()
        return receiver
    }
    if (id == 11) {
        receiver = Ping_from_Transducer_Board_to_Temperature_Board_1()
        return receiver
    }
    if (id == 11) {
        receiver = Ping_from_Transducer_Board_to_Temperature_Board_2()
        return receiver
    }
    if (id == 11) {
        receiver = Ping_from_Transducer_Board_to_Transducer_Board()
        return receiver
    }
    if (id == 11) {
        receiver = Ping_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 13) {
        receiver = Pong_from_Controller_Board_to_Controller_Board()
        return receiver
    }
    if (id == 13) {
        receiver = Pong_from_Controller_Board_to_Temperature_Board_1()
        return receiver
    }
    if (id == 13) {
        receiver = Pong_from_Controller_Board_to_Temperature_Board_2()
        return receiver
    }
    if (id == 13) {
        receiver = Pong_from_Controller_Board_to_Transducer_Board()
        return receiver
    }
    if (id == 13) {
        receiver = Pong_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 17) {
        receiver = Pong_from_Ground_Controller_to_Controller_Board()
        return receiver
    }
    if (id == 17) {
        receiver = Pong_from_Ground_Controller_to_Temperature_Board_1()
        return receiver
    }
    if (id == 17) {
        receiver = Pong_from_Ground_Controller_to_Temperature_Board_2()
        return receiver
    }
    if (id == 17) {
        receiver = Pong_from_Ground_Controller_to_Transducer_Board()
        return receiver
    }
    if (id == 17) {
        receiver = Pong_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 14) {
        receiver = Pong_from_Temperature_Board_1_to_Controller_Board()
        return receiver
    }
    if (id == 14) {
        receiver = Pong_from_Temperature_Board_1_to_Temperature_Board_1()
        return receiver
    }
    if (id == 14) {
        receiver = Pong_from_Temperature_Board_1_to_Temperature_Board_2()
        return receiver
    }
    if (id == 14) {
        receiver = Pong_from_Temperature_Board_1_to_Transducer_Board()
        return receiver
    }
    if (id == 14) {
        receiver = Pong_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 15) {
        receiver = Pong_from_Temperature_Board_2_to_Controller_Board()
        return receiver
    }
    if (id == 15) {
        receiver = Pong_from_Temperature_Board_2_to_Temperature_Board_1()
        return receiver
    }
    if (id == 15) {
        receiver = Pong_from_Temperature_Board_2_to_Temperature_Board_2()
        return receiver
    }
    if (id == 15) {
        receiver = Pong_from_Temperature_Board_2_to_Transducer_Board()
        return receiver
    }
    if (id == 15) {
        receiver = Pong_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 16) {
        receiver = Pong_from_Transducer_Board_to_Controller_Board()
        return receiver
    }
    if (id == 16) {
        receiver = Pong_from_Transducer_Board_to_Temperature_Board_1()
        return receiver
    }
    if (id == 16) {
        receiver = Pong_from_Transducer_Board_to_Temperature_Board_2()
        return receiver
    }
    if (id == 16) {
        receiver = Pong_from_Transducer_Board_to_Transducer_Board()
        return receiver
    }
    if (id == 16) {
        receiver = Pong_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 23) {
        receiver = RtcDate_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 27) {
        receiver = RtcDate_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 24) {
        receiver = RtcDate_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 25) {
        receiver = RtcDate_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 26) {
        receiver = RtcDate_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 28) {
        receiver = RtcTime_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 32) {
        receiver = RtcTime_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 29) {
        receiver = RtcTime_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 30) {
        receiver = RtcTime_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 31) {
        receiver = RtcTime_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 50) {
        receiver = Telemetry__ControllerBoard_edda_controller_00_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 51) {
        receiver = Telemetry__ControllerBoard_edda_controller_01_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 52) {
        receiver = Telemetry__ControllerBoard_edda_controller_02_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 53) {
        receiver = Telemetry__ControllerBoard_edda_controller_03_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 54) {
        receiver = Telemetry__ControllerBoard_edda_controller_04_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 55) {
        receiver = Telemetry__ControllerBoard_edda_controller_05_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 56) {
        receiver = Telemetry__ControllerBoard_edda_controller_06_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 57) {
        receiver = Telemetry__ControllerBoard_edda_controller_07_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 58) {
        receiver = Telemetry__ControllerBoard_edda_controller_08_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 59) {
        receiver = Telemetry__ControllerBoard_edda_controller_09_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 60) {
        receiver = Telemetry__ControllerBoard_edda_controller_10_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 61) {
        receiver = Telemetry__ControllerBoard_edda_controller_11_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 62) {
        receiver = Telemetry__ControllerBoard_edda_controller_12_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 63) {
        receiver = Telemetry__ControllerBoard_edda_controller_13_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 64) {
        receiver = Telemetry__ControllerBoard_edda_controller_14_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 65) {
        receiver = Telemetry__ControllerBoard_edda_controller_15_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 66) {
        receiver = Telemetry__ControllerBoard_edda_controller_16_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 67) {
        receiver = Telemetry__ControllerBoard_edda_controller_17_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 68) {
        receiver = Telemetry__ControllerBoard_edda_controller_18_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 69) {
        receiver = Telemetry__ControllerBoard_edda_controller_19_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 152) {
        receiver = Telemetry__ControllerBoard_sindri_00_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 153) {
        receiver = Telemetry__ControllerBoard_sindri_01_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 154) {
        receiver = Telemetry__ControllerBoard_sindri_02_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 155) {
        receiver = Telemetry__ControllerBoard_sindri_03_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 156) {
        receiver = Telemetry__ControllerBoard_sindri_04_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 157) {
        receiver = Telemetry__ControllerBoard_sindri_05_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 158) {
        receiver = Telemetry__ControllerBoard_sindri_06_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 159) {
        receiver = Telemetry__ControllerBoard_sindri_07_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 160) {
        receiver = Telemetry__ControllerBoard_sindri_08_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 161) {
        receiver = Telemetry__ControllerBoard_sindri_09_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 162) {
        receiver = Telemetry__ControllerBoard_sindri_10_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 163) {
        receiver = Telemetry__ControllerBoard_sindri_11_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 164) {
        receiver = Telemetry__ControllerBoard_sindri_12_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 70) {
        receiver = Telemetry__GroundController_edda_ground_00_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 71) {
        receiver = Telemetry__GroundController_edda_ground_01_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 72) {
        receiver = Telemetry__GroundController_edda_ground_02_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 73) {
        receiver = Telemetry__GroundController_edda_ground_03_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 74) {
        receiver = Telemetry__GroundController_edda_ground_04_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 75) {
        receiver = Telemetry__GroundController_edda_ground_05_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 76) {
        receiver = Telemetry__GroundController_edda_ground_06_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 77) {
        receiver = Telemetry__GroundController_edda_ground_07_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 78) {
        receiver = Telemetry__GroundController_edda_ground_08_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 79) {
        receiver = Telemetry__GroundController_edda_ground_09_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 80) {
        receiver = Telemetry__GroundController_edda_ground_10_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 81) {
        receiver = Telemetry__GroundController_edda_ground_11_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 82) {
        receiver = Telemetry__GroundController_edda_ground_12_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 83) {
        receiver = Telemetry__GroundController_edda_ground_13_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 84) {
        receiver = Telemetry__GroundController_edda_ground_14_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 85) {
        receiver = Telemetry__GroundController_edda_ground_15_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 86) {
        receiver = Telemetry__GroundController_edda_ground_16_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 87) {
        receiver = Telemetry__GroundController_edda_ground_17_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 88) {
        receiver = Telemetry__GroundController_edda_ground_18_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 89) {
        receiver = Telemetry__GroundController_edda_ground_19_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 90) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_00_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 91) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_01_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 92) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_02_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 93) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_03_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 94) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_04_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 95) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_05_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 96) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_06_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 97) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_07_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 98) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_08_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 99) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_09_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 100) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_10_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 101) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_11_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 102) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_12_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 103) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_13_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 104) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_14_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 105) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_15_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 106) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_16_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 107) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_17_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 108) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_18_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 109) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_19_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 110) {
        receiver = Telemetry__TemperatureBoard1_edda_temperature_1_20_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 165) {
        receiver = Telemetry__TemperatureBoard1_sindri_00_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 166) {
        receiver = Telemetry__TemperatureBoard1_sindri_01_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 167) {
        receiver = Telemetry__TemperatureBoard1_sindri_02_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 168) {
        receiver = Telemetry__TemperatureBoard1_sindri_03_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 169) {
        receiver = Telemetry__TemperatureBoard1_sindri_04_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 170) {
        receiver = Telemetry__TemperatureBoard1_sindri_05_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 171) {
        receiver = Telemetry__TemperatureBoard1_sindri_06_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 111) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_00_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 112) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_01_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 113) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_02_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 114) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_03_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 115) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_04_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 116) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_05_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 117) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_06_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 118) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_07_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 119) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_08_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 120) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_09_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 121) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_10_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 122) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_11_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 123) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_12_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 124) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_13_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 125) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_14_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 126) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_15_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 127) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_16_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 128) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_17_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 129) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_18_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 130) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_19_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 131) {
        receiver = Telemetry__TemperatureBoard2_edda_temperature_2_20_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 172) {
        receiver = Telemetry__TemperatureBoard2_sindri_00_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 173) {
        receiver = Telemetry__TemperatureBoard2_sindri_01_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 174) {
        receiver = Telemetry__TemperatureBoard2_sindri_02_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 175) {
        receiver = Telemetry__TemperatureBoard2_sindri_03_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 176) {
        receiver = Telemetry__TemperatureBoard2_sindri_04_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 177) {
        receiver = Telemetry__TemperatureBoard2_sindri_05_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 178) {
        receiver = Telemetry__TemperatureBoard2_sindri_06_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 179) {
        receiver = Telemetry__TemperatureBoard2_sindri_07_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 132) {
        receiver = Telemetry__TransducerBoard_edda_transducer_00_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 133) {
        receiver = Telemetry__TransducerBoard_edda_transducer_01_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 134) {
        receiver = Telemetry__TransducerBoard_edda_transducer_02_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 135) {
        receiver = Telemetry__TransducerBoard_edda_transducer_03_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 136) {
        receiver = Telemetry__TransducerBoard_edda_transducer_04_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 137) {
        receiver = Telemetry__TransducerBoard_edda_transducer_05_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 138) {
        receiver = Telemetry__TransducerBoard_edda_transducer_06_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 139) {
        receiver = Telemetry__TransducerBoard_edda_transducer_07_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 140) {
        receiver = Telemetry__TransducerBoard_edda_transducer_08_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 141) {
        receiver = Telemetry__TransducerBoard_edda_transducer_09_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 142) {
        receiver = Telemetry__TransducerBoard_edda_transducer_10_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 143) {
        receiver = Telemetry__TransducerBoard_edda_transducer_11_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 144) {
        receiver = Telemetry__TransducerBoard_edda_transducer_12_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 145) {
        receiver = Telemetry__TransducerBoard_edda_transducer_13_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 146) {
        receiver = Telemetry__TransducerBoard_edda_transducer_14_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 147) {
        receiver = Telemetry__TransducerBoard_edda_transducer_15_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 148) {
        receiver = Telemetry__TransducerBoard_edda_transducer_16_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 149) {
        receiver = Telemetry__TransducerBoard_edda_transducer_17_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 150) {
        receiver = Telemetry__TransducerBoard_edda_transducer_18_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 151) {
        receiver = Telemetry__TransducerBoard_edda_transducer_19_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 180) {
        receiver = Telemetry__TransducerBoard_sindri_00_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 181) {
        receiver = Telemetry__TransducerBoard_sindri_01_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 182) {
        receiver = Telemetry__TransducerBoard_sindri_02_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 183) {
        receiver = Telemetry__TransducerBoard_sindri_03_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 184) {
        receiver = Telemetry__TransducerBoard_sindri_04_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 185) {
        receiver = Telemetry__TransducerBoard_sindri_05_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 186) {
        receiver = Telemetry__TransducerBoard_sindri_06_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 187) {
        receiver = Telemetry__TransducerBoard_sindri_07_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 188) {
        receiver = Telemetry__TransducerBoard_sindri_08_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 189) {
        receiver = Telemetry__TransducerBoard_sindri_09_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 42) {
        receiver = TelemetryMetaFrame_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 40) {
        receiver = TelemetryMetaFrame_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 46) {
        receiver = TelemetryMetaFrame_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 48) {
        receiver = TelemetryMetaFrame_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 44) {
        receiver = TelemetryMetaFrame_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 43) {
        receiver = TelemetryMetaTime_from_Controller_Board_to_Ground_Controller()
        return receiver
    }
    if (id == 41) {
        receiver = TelemetryMetaTime_from_Ground_Controller_to_Ground_Controller()
        return receiver
    }
    if (id == 47) {
        receiver = TelemetryMetaTime_from_Temperature_Board_1_to_Ground_Controller()
        return receiver
    }
    if (id == 49) {
        receiver = TelemetryMetaTime_from_Temperature_Board_2_to_Ground_Controller()
        return receiver
    }
    if (id == 45) {
        receiver = TelemetryMetaTime_from_Transducer_Board_to_Ground_Controller()
        return receiver
    }
}
